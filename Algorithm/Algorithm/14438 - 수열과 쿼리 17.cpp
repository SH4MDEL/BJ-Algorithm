#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

int n, m;

int init(vector<int>& arr, vector<int>& tree, int node, int start, int end)
{
	if (start == end) return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = min(init(arr, tree, node * 2, start, mid), init(arr, tree, node * 2 + 1, mid + 1, end));
}

int update(vector<int>& tree, int node, int start, int end, int index, int diff)
{
	if (index < start || index > end) return tree[node];

	if (start != end) {
		int mid = (start + end) / 2;
		return tree[node] = min(update(tree, node * 2, start, mid, index, diff), update(tree, node * 2 + 1, mid + 1, end, index, diff));
	}
	return tree[node] = diff;
}

int find(vector<int>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return inf + inf;

	if (left <= start && right >= end) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return min(find(tree, node * 2, start, mid, left, right), find(tree, node * 2 + 1, mid + 1, end, left, right));
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n;
	vector<int> arr(n);
	vector<int> segtree(n * 4);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	init(arr, segtree, 1, 0, n - 1);
	cin >> m;
	int query, a, b;
	for (int i = 0; i < m; ++i) {
		cin >> query >> a >> b;
		if (query == 1) {
			arr[a - 1] = b;
			update(segtree, 1, 0, n - 1, a - 1, b);
		}
		if (query == 2) {
			cout << find(segtree, 1, 0, n - 1, a - 1, b - 1) << endl;
		}
	}
}