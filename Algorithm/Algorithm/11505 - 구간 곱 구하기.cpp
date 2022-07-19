#include <iostream>
#include <vector>
#define endl "\n"
#define inf 987654321
#define mod 1'000'000'007
using namespace std;

long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	if (start == end) return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = ((init(arr, tree, node * 2, start, mid) % mod) * (init(arr, tree, node * 2 + 1, mid + 1, end) % mod)) % mod;
}

long long update(vector<long long>& tree, int node, int start, int end, int index, long long diff)
{
	if (start > index || index > end) return tree[node];

	if (start == end) return tree[node] = diff;

	int mid = (start + end) / 2;
	return tree[node] = ((update(tree, node * 2, start, mid, index, diff) % mod) 
		* (update(tree, node * 2 + 1, mid + 1, end, index, diff) % mod)) % mod;
}

long long find(vector<long long>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 1;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return ((find(tree, node * 2, start, mid, left, right) % mod) * (find(tree, node * 2 + 1, mid + 1, end, left, right) % mod)) % mod;
}

void print_all(vector<long long>& tree, int node, int start, int end)
{
	if (start == end) {
		cout << tree[node] << " ";
		return;
	}
	int mid = (start + end) / 2;
	print_all(tree, node * 2, start, mid);
	print_all(tree, node * 2 + 1, mid + 1, end);
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<long long> arr(n);
	vector<long long> segtree(n * 4);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	init(arr, segtree, 1, 0, n - 1);

	int query, a, b;
	for (int i = 0; i < m + k; ++i) {
		cin >> query >> a >> b;
		if (query == 1) {
			arr[a - 1] = (long long)b;
			update(segtree, 1, 0, n - 1, a - 1, (long long)b);
			cout << endl;
		}
		if (query == 2) {
			cout << find(segtree, 1, 0, n - 1, a - 1, b - 1) << endl;
		}
	}
}