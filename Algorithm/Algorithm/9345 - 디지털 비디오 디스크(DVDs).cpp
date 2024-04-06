#include <iostream>
#include <vector>
#include <ranges>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int t, n, k;
struct Node {
	int m, M;
};

Node init(vector<Node>& tree, int node, int start, int end)
{
	if (start == end) {
		tree[node].m = tree[node].M = start;
		return tree[node];
	}

	int mid = (start + end) / 2;
	Node l = init(tree, node * 2, start, mid);
	Node r = init(tree, node * 2 + 1, mid + 1, end);
	tree[node].m = min(l.m, r.m);
	tree[node].M = max(l.M, r.M);
	return tree[node];
}

Node seg_find(vector<Node>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return { inf, -inf };
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	Node l = seg_find(tree, node * 2, start, mid, left, right);
	Node r = seg_find(tree, node * 2 + 1, mid + 1, end, left, right);
	return { min(l.m, r.m), max(l.M, r.M) };
}

Node seg_update(vector<Node>& tree, int node, int start, int end, int index, int to)
{
	if (index < start || end < index) return tree[node];

	if (start == end) {
		tree[node].m = tree[node].M = to;
		return tree[node];
	}

	int mid = (start + end) / 2;
	Node l = seg_update(tree, node * 2, start, mid, index, to);
	Node r = seg_update(tree, node * 2 + 1, mid + 1, end, index, to);
	tree[node].m = min(l.m, r.m);
	tree[node].M = max(l.M, r.M);
	return tree[node];
}

int main()
{
	fastip; sws;

	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<Node> segtree(n * 4);
		vector<int> pos(n);
		for (const auto& i : views::iota(0, n)) { pos[i] = i; }

		init(segtree, 1, 0, n - 1);
		while (k--) {
			int q, a, b;
			cin >> q >> a >> b;
			if (q == 0) {
				seg_update(segtree, 1, 0, n - 1, pos[a], b);
				seg_update(segtree, 1, 0, n - 1, pos[b], a);
				swap(pos[a], pos[b]);
			}
			else {
				auto node = seg_find(segtree, 1, 0, n - 1, a, b);
				if (node.m == a && node.M == b) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		}
	}

}