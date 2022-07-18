#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
#define inf 987654321
using namespace std;

int n;

long long init_sum(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = init_sum(arr, tree, node * 2, start, mid) + init_sum(arr, tree, node * 2 + 1, mid + 1, end);
}

int init_min(vector<long long>& arr, vector<int>& tree, int node, int start, int end)
{
	if (start == end) return tree[node] = start;

	int mid = (start + end) / 2;

	int a = init_min(arr, tree, node * 2, start, mid);
	int b = init_min(arr, tree, node * 2 + 1, mid + 1, end);
	if (arr[a] > arr[b]) return tree[node] = b;
	if (arr[a] < arr[b]) return tree[node] = a;
	return tree[node] = min(a, b);
}

long long find_sum(vector<long long>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return find_sum(tree, node * 2, start, mid, left, right) + find_sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

int find_min(vector<long long>& arr, vector<int>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return n;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	int a = find_min(arr, tree, node * 2, start, mid, left, right);
	int b = find_min(arr, tree, node * 2 + 1, mid + 1, end, left, right);
	if (arr[a] > arr[b]) return b;
	if (arr[a] < arr[b]) return a;
	return min(a, b);
}

long long find_answer(vector<long long>& arr, vector<long long>& sumtree, vector<int>& mintree, int node, int start, int end)
{
	if (start == end) return arr[start] * arr[start];
	int arrnum = find_min(arr, mintree, node, 0, n - 1, start, end);
	long long a = find_sum(sumtree, node, 0, n - 1, start, end) * arr[arrnum];
	if (arrnum > start) {
		a = max(a, find_answer(arr, sumtree, mintree, node, start, arrnum - 1));
	}
	if (arrnum < end) {
		a = max(a, find_answer(arr, sumtree, mintree, node, arrnum + 1, end));
	}
	return a;

}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n;
	vector<long long> arr(n + 1);
	vector<long long> sumtree(n * 4);
	vector<int> mintree(n * 4);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	arr[n] = inf;
	init_sum(arr, sumtree, 1, 0, n - 1);
	init_min(arr, mintree, 1, 0, n - 1);

	cout << find_answer(arr, sumtree, mintree, 1, 0, n - 1) << endl;
}