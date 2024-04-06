#include <iostream>
#include <ranges>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int n, m, now;
vector<int> segtree, lazy, children[100100];
int istart[100100], iend[100100];

void make_tree(int me)
{
	istart[me] = ++now;
	for (const auto& child : children[me]) {
		make_tree(child);
	}
	iend[me] = now;
}

void lazy_update(int node, int start, int end, int left, int right)
{
	if (lazy[node]) {
		segtree[node] += lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void range_update(int node, int start, int end, int left, int right, int value)
{
	lazy_update(node, start, end, left, right);
	if (start > right || end < left) return;

	segtree[node] += value;
	if (left <= start && end <= right) {
		if (start != end) {
			lazy[node * 2] += value;
			lazy[node * 2 + 1] += value;
		}
		return;
	}

	int mid = (start + end) / 2;
	range_update(node * 2, start, mid, left, right, value);
	range_update(node * 2 + 1, mid + 1, end, left, right, value);
}

int seg_find(int node, int start, int end, int index)
{
	lazy_update(node, start, end, index, index);
	if (start > index || index > end) return 0;
	if (start == end) return segtree[node];

	int mid = (start + end) / 2;
	return seg_find(node * 2, start, mid, index) + 
		seg_find(node * 2 + 1, mid + 1, end, index);
}

int main()
{
	fastip; sws;

	cin >> n >> m;
	segtree.resize(n * 4);
	lazy.resize(n * 4);
	int parent;
	cin >> parent;
	for (const auto& i : views::iota(2, n + 1)) {
		cin >> parent;
		children[parent].push_back(i);
	}
	make_tree(1);
	while (m--) {
		int q; cin >> q;
		if (q == 1) {
			int a, b; cin >> a >> b;
			range_update(1, 1, n, istart[a], iend[a], b);
		}
		else {
			int a; cin >> a;
			cout << seg_find(1, 1, n, istart[a]) << endl;
		}
	}
}