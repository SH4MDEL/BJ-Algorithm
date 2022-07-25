#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

int update(pair<int, int> input, vector<int>& tree, int node, int start, int end)
{
	if (input.first < start || input.first > end) return tree[node];

	if (start == end) return tree[node] = 1;

	int mid = (start + end) / 2;
	update(input, tree, node * 2, start, mid);
	update(input, tree, node * 2 + 1, mid + 1, end);
	return tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int find(vector<int>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return find(tree, node * 2, start, mid, left, right) + find(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);
	vector<int> segtree(n * 4);
	vector<int> answer(n);
	for (int i = 0; i < n; ++i) {
		arr[i].first = i;
		cin >> arr[i].second;
	}
	sort(arr.begin(), arr.end(), [](pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
		});
	for (int i = 0; i < n; ++i) {
		arr[i].second = i;
	}
	for (int i = 0; i < n; ++i) {
		update(arr[i], segtree, 1, 0, n - 1);
		answer[arr[i].first] = find(segtree, 1, 0, n - 1, 0, arr[i].first);
	}
	for (const auto& elm : answer) cout << elm << endl;
	
}