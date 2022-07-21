#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

int n, m;

struct Query {
	int index, query1, i, j;
};

long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	if (start == end) return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

long long find_sum(vector<long long>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return find_sum(tree, node * 2, start, mid, left, right) + find_sum(tree, node * 2 + 1, mid + 1, end, left, right);
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

	cin >> n;

	vector<long long> arr(n);
	vector<long long> segtree(n * 4);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	init(arr, segtree, 1, 0, n - 1);

	int query, a, b, c;
	vector<pair<int, int>> query1;
	vector<Query> query2;
	int query2index = 0;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> query;
		if (query == 1) {
			cin >> a >> b;
			query1.push_back(make_pair(a, b));
		}
		if (query == 2) {
			cin >> a >> b >> c;
			query2.push_back(Query(query2index, a, b, c));
			++query2index;
		}
	}
	vector<long long> answer(query2index);
	sort(query2.begin(), query2.end(), [](const Query& a, const Query& b) {
		return a.query1 < b.query1;
		});
	int query1index = 0;
	query2index = 0;
	while (query2index < query2.size()) {
		while (query2[query2index].query1 > query1index && query1index < query1.size()) {
			long long diff = query1[query1index].second - arr[query1[query1index].first - 1];
			arr[query1[query1index].first - 1] = query1[query1index].second;
			update(segtree, 1, 0, n - 1, query1[query1index].first - 1, diff);
			++query1index;
		}
		answer[query2[query2index].index] = find_sum(segtree, 1, 0, n - 1, query2[query2index].i - 1, query2[query2index].j - 1);
		++query2index;
	}
	for (const auto& elm : answer) {
		cout << elm << endl;
	}
}