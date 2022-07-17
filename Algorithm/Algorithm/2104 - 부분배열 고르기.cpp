#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
#define inf 987654321
using namespace std;

long long init_sum(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	if (start == end) {
		return tree[node] = start;
	}
	int mid = (start + end) / 2;
	return tree[node] = init_sum(arr, tree, node * 2, start, mid) + init_sum(arr, tree, node * 2 + 1, mid + 1, end);
}

long long init_min(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	if (start == end) {
		return tree[node] = start;
	}
	int mid = (start + end) / 2;
	return tree[node] = min(init_sum(arr, tree, node * 2, start, mid), init_sum(arr, tree, node * 2 + 1, mid + 1, end));
}

long long find_sum(vector<long long>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return find_sum(tree, node * 2, start, mid, left, right) + find_sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

long long find_min(vector<long long>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return inf;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return min(find_min(tree, node * 2, start, mid, left, right), find_min(tree, node * 2 + 1, mid + 1, end, left, right));
}

long long init_seg(vector<long long>& segtree, vector<long long>& sumtree, vector<long long>& mintree, int node, int start, int end)
{
	if (start == end) return segtree[node] = segtree[node] * sumtree[node];

	int mid = (start + end) / 2;
	long long a = init_seg(segtree, sumtree, mintree, node * 2, start, mid);
	return segtree[node];
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<long long> arr(n);
	vector<long long> sumtree(n * 4);
	vector<long long> mintree(n * 4);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	init_sum(arr, sumtree, 1, 0, n - 1);
	init_min(arr, mintree, 1, 0, n - 1);

	cout << find_min(mintree, 1, 0, n - 1, 0, n - 1) * find_sum(sumtree, 1, 0, n - 1, 0, n - 1) << endl;
}