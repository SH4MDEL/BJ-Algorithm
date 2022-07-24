#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

void update(pair<int, int> input, vector<pair<int, int>>& tree, int node, int start, int end)
{
	if (input.first < start || input.first > end) return;

	if (start == end) tree[node] = 
}

int main()
{
	int n;
	vector<pair<int, int>> arr(n);
	vector<pair<int, int>> segtree(n * 4);
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
	
}