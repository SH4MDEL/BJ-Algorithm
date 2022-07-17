#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
#define inf 1087654321
using namespace std;

int n, m;

int init(vector<int>& arr, vector<int>& tree, int node, int start, int end)
{
	if (start == end) return tree[node] = start;

	int mid = (start + end) / 2;

	int a = init(arr, tree, node * 2, start, mid);
	int b = init(arr, tree, node * 2 + 1, mid + 1, end);
	if (arr[a] > arr[b]) return tree[node] = b;
	if (arr[a] < arr[b]) return tree[node] = a;
	return tree[node] = min(a, b);
}

int update(vector<int>& arr, vector<int>& tree, int node, int start, int end, int index)
{
	if (index < start || index > end) return tree[node];

	if (start == end) {
		return tree[node] = index;
	}

	int mid = (start + end) / 2;
	int a = update(arr, tree, node * 2, start, mid, index);
	int b = update(arr, tree, node * 2 + 1, mid + 1, end, index);

	if (arr[a] > arr[b]) return tree[node] = b;
	if (arr[a] < arr[b]) return tree[node] = a;
	return tree[node] = min(a, b);
}

int find(vector<int>& arr, vector<int>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return n;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	int a = find(arr, tree, node * 2, start, mid, left ,right);
	int b = find(arr, tree, node * 2 + 1, mid + 1, end, left, right);
	if (arr[a] > arr[b]) return b;
	if (arr[a] < arr[b]) return a;
	return min(a, b);
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n;
	vector<int> arr(n + 1);
	vector<int> segtree(n * 4);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	arr[n] = inf;
	init(arr, segtree, 1, 0, n - 1);
	cin >> m;
	int query, a, b;
	for (int i = 0; i < m; ++i) {
		cin >> query >> a >> b;
		if (query == 1) {
			arr[a - 1] = b;
			update(arr, segtree, 1, 0, n - 1, a - 1);
		}
		if (query == 2) {
			cout << find(arr, segtree, 1, 0, n - 1, a - 1, b - 1) + 1 << endl;;
		}
	}
 }