#include <iostream>
#include <vector>
#define endl "\n"
#define inf 987654321
using namespace std;

int init(vector<int>& arr, vector<int>& tree, int node, int start, int end)
{
	if (start == end) return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = init(arr, tree, node * 2, start, mid) ^ init(arr, tree, node * 2 + 1, mid + 1, end);
}

void update_lazy(vector<int>& tree, vector<int>& lazy, int node, int start, int end)
{
	if (lazy[node] != 0) {
		if ((end - start + 1) % 2 == 1) {
			tree[node] ^= lazy[node];
		}
		if (start != end) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(vector<int>& tree, vector<int>& lazy, int node, int start, int end, int left, int right, int k)
{
	update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start) return;

	if (left <= start && end <= right) {
		if ((end - start + 1) % 2 == 1) {
			tree[node] ^= k;
		}
		if (start != end) {
			lazy[node * 2] ^= k;
			lazy[node * 2 + 1] ^= k;
		}
		return;
	}
	int mid = (start + end) / 2;
	update_range(tree, lazy, node * 2, start, mid, left, right, k);
	update_range(tree, lazy, node * 2 + 1, mid + 1, end, left, right, k);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int find_range(vector<int>& tree, vector<int>& lazy, int node, int start, int end, int left, int right)
{
	update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return find_range(tree, lazy, node * 2, start, mid, left, right) ^ find_range(tree, lazy, node * 2 + 1, mid + 1, end, left, right);

}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	int n, m;
	cin >> n;
	vector<int> arr(n);
	vector<int> segtree(n * 4);
	vector<int> lazy(n * 4);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	init(arr, segtree, 1, 0, n - 1);
	cin >> m;
	int query, a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> query;
		if (query == 1) {
			cin >> a >> b >> c;
			if (a > b) swap(a, b);
			update_range(segtree, lazy, 1, 0, n - 1, a, b, c);
		}
		if (query == 2) {
			cin >> a >> b;
			if (a > b) swap(a, b);
			cout << find_range(segtree, lazy, 1, 0, n - 1, a, b) << endl;
		}
	}
}