#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

int n, m;

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff)
{
	if (index > end || index < start) return;

	tree[node] += diff;

	if (start != end) {
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

long long find(vector<long long>& tree, int node, int left, int right, int start, int end)
{
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && right >= end) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return find(tree, node * 2, left, right, start, mid) + find(tree, node * 2 + 1, left, right, mid + 1, end);
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n >> m;
	vector<long long> arr(n);
	vector<long long> segtree(n * 4);

	int query, a, b;
	for (int i = 0; i < m; ++i) {
		cin >> query >> a >> b;
		if (query == 0) {
			if (a > b) {
				cout << find(segtree, 1, b - 1, a - 1, 0, n - 1) << endl;
			}
			else {
				cout << find(segtree, 1, a - 1, b - 1, 0, n - 1) << endl;
			}
		}
		if (query == 1) {
			long long diff = b - arr[a - 1];
			arr[a - 1] = b;
			update(segtree, 1, 0, n - 1, a - 1, diff);
		}
	}
}