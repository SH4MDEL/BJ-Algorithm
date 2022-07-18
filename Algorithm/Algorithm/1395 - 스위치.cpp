#include <iostream>
#include <vector>
#define endl "\n"
#define inf 987654321
using namespace std;

void update_lazy(vector<int>& tree, vector<int>& lazy, int node, int start, int end)
{
	if (lazy[node] != 0) {
		if (lazy[node] % 2 == 1) {
			tree[node] = (end - start + 1) - tree[node];
		}
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(vector<int>& tree, vector<int>& lazy, int node, int start, int end, int left, int right)
{
	update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start) return;

	if (left <= start && end <= right) {
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] += 1;
			lazy[node * 2 + 1] += 1;
		}
		return;
	}

	int mid = (start + end) / 2;
	update_range(tree, lazy, node * 2, start, mid, left, right);
	update_range(tree, lazy, node * 2 + 1, mid + 1, end, left, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int find_range(vector<int>& tree, vector<int>& lazy, int node, int start, int end, int left, int right)
{
	update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;
	return find_range(tree, lazy, node * 2, start, mid, left, right) + find_range(tree, lazy, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> lazy(n * 4, 0);
	vector<int> segtree(n * 4, 0);
	int query, a, b;
	for (int i = 0; i < m; ++i) {
		cin >> query >> a >> b;
		if (query == 0) {
			update_range(segtree, lazy, 1, 0, n - 1, a - 1, b - 1);
		}
		if (query == 1) {
			cout << find_range(segtree, lazy, 1, 0, n - 1, a - 1, b - 1) << endl;
		}
	}
}