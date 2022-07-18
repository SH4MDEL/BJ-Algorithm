#include <iostream>
#include <vector>
#define endl "\n"
#define inf 987654321
using namespace std;

long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	if (start == end) return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

void update_lazy(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end)
{
	if (lazy[node] != 0) {
		tree[node] += lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
		return;
	}
}

void update_range(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right, long long diff_start)
{
	update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start) return;

	if (left <= start && end <= right) {
		tree[node] += (end - start + 1) * (end - start + 2 * diff_start) / 2;
	}
}