#include <iostream>
#include <vector>
#define endl "\n"
#define inf 987654321
using namespace std;

long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

void update_lazy(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end)
{
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right, long long diff)
{
	update_lazy(tree, lazy, node, start, end);

	if (left > end || right < start) return;

	if (left <= start && right >= end) {
		tree[node] += (end - start + 1) * diff;
		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}

	int mid = (start + end) / 2;
	update_range(tree, lazy, node * 2, start, mid, left, right, diff);
	update_range(tree, lazy, node * 2 + 1, mid + 1, end, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long find(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right)
{
	update_lazy(tree, lazy, node, start, end);

	if (left > end || right < start) return 0;

	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;
	return find(tree, lazy, node * 2, start, mid, left, right) + find(tree, lazy, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	int n, m;
	cin >> n;
	vector<long long> arr(n);
	vector<long long> segtree(n * 4);
	vector<long long> lazy(n * 4);

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
			update_range(segtree, lazy, 1, 0, n - 1, a - 1, b - 1, c);
		}
		if (query == 2) {
			cin >> a;
			cout << find(segtree, lazy, 1, 0, n - 1, a - 1, a - 1) << endl;
		}
	}
}