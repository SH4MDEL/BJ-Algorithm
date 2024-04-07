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
vector<int> segtree, children[100100];
int istart[100100], iend[100100];

void make_tree(int me)
{
	istart[me] = ++now;
	for (const auto& child : children[me]) {
		make_tree(child);
	}
	iend[me] = now;
}

void seg_update(int node, int start, int end, int index, int value)
{
	if (index < start || end < index) return;
	
	segtree[node] += value;
	if (start == end) return;

	int mid = (start + end) / 2;
	seg_update(node * 2, start, mid, index, value);
	seg_update(node * 2 + 1, mid + 1, end, index, value);
}

int seg_find(int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return segtree[node];

	int mid = (start + end) / 2;
	return seg_find(node * 2, start, mid, left, right) + seg_find(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	fastip; sws;

	cin >> n >> m;
	int parent;
	cin >> parent;
	for (const auto& i : views::iota(2, n + 1)) {
		cin >> parent;
		children[parent].push_back(i);
	}
	make_tree(1);
	segtree.resize(n * 4);
	while (m--) {
		int q; cin >> q;
		if (q == 1) {
			int a, b; cin >> a >> b;
			seg_update(1, 1, n, istart[a], b);
		}
		else {
			int a; cin >> a;
			cout << seg_find(1, 1, n, istart[a], iend[a]) << endl;
		}
	}

}