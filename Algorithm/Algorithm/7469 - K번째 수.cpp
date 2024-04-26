#include <iostream>
#include <algorithm>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int n, m;
vector<int> v;
vector<vector<int>> segtree;

void make_tree(int node, int start, int end)
{
	if (start == end) {
		segtree[node].push_back(v[start]);
		return;
	}

	int mid = (start + end) / 2;
	make_tree(node * 2, start, mid);
	make_tree(node * 2 + 1, mid + 1, end);
	segtree[node].resize(segtree[node * 2].size() + segtree[node * 2 + 1].size());
	merge(segtree[node * 2].begin(), segtree[node * 2].end(),
		segtree[node * 2 + 1].begin(), segtree[node * 2 + 1].end(),
		segtree[node].begin());
}

// k보다 같거나 작은 수가 몇 개인지?
int segtree_find(int node, int start, int end, int left, int right, int k)
{
	if (start > right || end < left) return 0;

	if (left <= start && end <= right) {
		return upper_bound(segtree[node].begin(), segtree[node].end(), k) - segtree[node].begin();
	}
	int mid = (start + end) / 2;
	return segtree_find(node * 2, start, mid, left, right, k) + 
		segtree_find(node * 2 + 1, mid + 1, end, left, right, k);
}

int main()
{
	fastip; sws;
	cin >> n >> m;
	v.resize(n + 1);
	segtree.resize(n * 4);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	make_tree(1, 1, n);
	while (m--) {
		int i, j, k;
		cin >> i >> j >> k;
		int s = -1'000'000'001, e = 1'000'000'001;
		while (s + 1 < e) {
			int m = (s + e) / 2;
			if (segtree_find(1, 1, n, i, j, m) < k) {
				s = m;
			}
			else e = m;
		}
		cout << e << endl;
	}
}