#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int n, m;
vector<int> arr;
vector<vector<int>> segtree;

void init(int node, int start, int end)
{
	if (start == end) {
		segtree[node].push_back(arr[start]);
		return;
	}

	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);

	segtree[node].resize(segtree[node * 2].size() + segtree[node * 2 + 1].size());
	merge(segtree[node * 2].begin(), segtree[node * 2].end(),
		segtree[node * 2 + 1].begin(), segtree[node * 2 + 1].end(),
		segtree[node].begin());
}

int search(int node, int start, int end, int left, int right, int value)
{
	if (start > right || end < left) return 0;
	if (left <= start && end <= right) {
		auto upper = upper_bound(segtree[node].begin(), segtree[node].end(), value);
		return (segtree[node].end() - upper);
	}
	int mid = (start + end) / 2;
	return search(node * 2, start, mid, left, right, value) +
		search(node * 2 + 1, mid + 1, end, left, right, value);
}

int main()
{
	fastip; sws;

	cin >> n;
	arr.resize(n + 1);
	segtree.resize(n * 4);
	for (const auto& i : views::iota(1, n + 1)) cin >> arr[i];
	init(1, 1, n);
	cin >> m;
	int last = 0;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		last = search(1, 1, n, a ^ last, b ^ last, c ^ last);
		cout << last << endl;
	}
}