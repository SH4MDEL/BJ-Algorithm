#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

int t, n, m;

long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

long long find(vector<long long>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;

	if (left <= start && right >= end) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return find(tree, node * 2, start, mid, left, right) + find(tree, node * 2 + 1, mid + 1, end, left, right);
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff)
{
	if (index < start || index > end) return;

	tree[node] += diff;

	if (start != end) {
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n >> m;
		vector<long long> answer;
		answer.reserve(m);
		vector<long long> arr(n, 1);
		arr.resize(n + m);
		vector<long long> segtree((n + m) * 4);
		init(arr, segtree, 1, 0, n + m - 1);

		for (int j = n - 1; auto& elm : arr) {
			elm = (long long)j;
			--j;
		}

		int query;
		for (int j = 0; j < m; ++j) {
			cin >> query;
			answer.push_back(find(segtree, 1, 0, n + m - 1, arr[query - 1], n + m - 1) - 1);
			update(segtree, 1, 0, n + m - 1, arr[query - 1], -1);
			update(segtree, 1, 0, n + m - 1, n + j, 1);

			arr[query - 1] = n + j;
		}

		for (const auto& elm : answer) {
			cout << elm << " ";
		}
		cout << endl;
	}
}