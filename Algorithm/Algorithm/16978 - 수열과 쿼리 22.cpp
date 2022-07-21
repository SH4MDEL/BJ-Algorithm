#include <iostream>
#include <vector>
#define endl "\n"
#define inf 987654321
using namespace std;

int n, m, k;

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
	cin >> n >> m >> k;

	vector<long long> arr(n);
	vector<long long> segtree(n * 4);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	init(arr, segtree, 1, 0, n - 1);

	long long query, a, b;
	for (int i = 0; i < m + k; ++i) {
		cin >> query >> a >> b;
		if (query == 1) {
			long long diff = (long long)b - arr[a - 1];
			arr[a - 1] = b;
			update(segtree, 1, 0, n - 1, a - 1, diff);
		}
		if (query == 2) {
			cout << find_sum(segtree, 1, 0, n - 1, a - 1, b - 1) << endl;
		}
	}
}