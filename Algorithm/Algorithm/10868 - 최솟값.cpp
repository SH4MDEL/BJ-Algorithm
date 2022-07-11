#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

int n, m;

long long init(vector<long long>& arr, vector<long long>&tree, int node, int start, int end)
{
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = min(init(arr, tree, node * 2, start, mid), init(arr, tree, node * 2 + 1, mid + 1, end));
}

long long find(vector<long long>& tree, int node, int left, int right, int start, int end)
{
	if (right < start || left > end) {
		return inf + inf;
	}
	if (left <= start && right >= end) {
		return tree[node];
	}

	int mid = (start + end) / 2;
	return min(find(tree, node * 2, left, right, start, mid), find(tree, node * 2 + 1, left, right, mid + 1, end));
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n >> m;
	vector<long long> arr(n);
	vector<long long> segtree(n * 4);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	init(arr, segtree, 1, 0, n - 1);
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		cout << find(segtree, 1, a - 1, b - 1, 0, n - 1) << endl;;
	}
}