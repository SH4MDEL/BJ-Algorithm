#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

int n, q;

long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

void update(vector<long long>& tree, int node, int start ,int end, int index, long long diff)
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

	cin >> n >> q;
	vector<long long> arr(n);
	vector<long long> segtree(n * 4);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	init(arr, segtree, 1, 0, n - 1);
	int x, y, a, b;
	for (int i = 0; i < q; ++i) {
		cin >> x >> y >> a >> b;
		if (x > y) {
			cout << find(segtree, 1, y - 1, x - 1, 0, n - 1) << endl;
		}
		else {
			cout << find(segtree, 1, x - 1, y - 1, 0, n - 1) << endl;
		}
		long long diff = b - arr[a - 1];
		arr[a - 1] = b;
		update(segtree, 1, 0, n - 1, a - 1, diff);
	}
}