#include <iostream>
#include <ranges>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int n, m;
int parent[500500];
int cost[500500];
vector<int> children[500500];
int index[500500];
int istart[500500], now;
int iend[500500];

void make_tree(int me)
{
	index[me] = ++now;
	istart[me] = now + 1;
	if (!children[me].empty()) {
		for (auto& child : children[me]) {
			make_tree(child);
		}
	}
	iend[me] = now;
}

vector<int> segtree;
vector<int> lazy;

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
	if (right < start || end < left) return;

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

	if (index < start || end < index) return 0;
	if (start == end) return segtree[node];

	int mid = (start + end) / 2;
	return seg_find(node * 2, start, mid, index) + seg_find(node * 2 + 1, mid + 1, end, index);
}

int main()
{
	fastip; sws;
	cin >> n >> m;
	cin >> cost[1];
	for (const auto i : views::iota(2, n + 1)) {
		int a, b;
		cin >> a >> b;
		cost[i] = a;
		parent[i] = b;
		children[b].push_back(i);
	}
	segtree.resize(n * 4);
	lazy.resize(n * 4);
	make_tree(1);
	for (const auto i : views::iota(0, m)) {
		char c;
		cin >> c;
		if (c == 'p') {
			int a, x;
			cin >> a >> x;
			if (children[a].empty()) continue;
			range_update(1, 1, n, istart[a], iend[a], x);
		}
		else {
			int a;
			cin >> a;
			cout << cost[a] + seg_find(1, 1, n, index[a]) << endl;
		}
	}
}