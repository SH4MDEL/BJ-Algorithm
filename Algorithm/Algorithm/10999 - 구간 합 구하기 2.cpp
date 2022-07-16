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

// 어떤 노드를 방문했을때마다 호출하여 갱신할 일이 있는지 확인해보고 있으면 갱신 후
// 자식 노드의 lazy 노드도 업데이트 해 준다.
void update_lazy(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end)
{
	if (lazy[node] != 0) {
		tree[node] += (long long)(end - start + 1) * lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right, long long diff)
{
	update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start) return;

	// 범위 안에 완전히 포함
	if (left <= start && right >= end) {
		tree[node] += (end - start + 1) * diff;
		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	int mid = (start + end) / 2;
	update_range(tree, lazy, node * 2, start, mid, left, right, diff);
	update_range(tree, lazy, node * 2 + 1, mid + 1, end, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long find_sum(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right)
{
	update_lazy(tree, lazy, node, start, end);

	if (start > right || end < left) return 0;

	if (left <= start && right >= end) return tree[node];

	int mid = (start + end) / 2;
	return find_sum(tree, lazy, node * 2, start, mid, left, right) + find_sum(tree, lazy, node * 2 + 1, mid + 1, end, left, right);
}

int n, m, k;
int a, b, c;
long long d;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);
	
	cin >> n >> m >> k;
	vector<long long> arr(n);
	vector<long long> segtree(n * 4);
	vector<long long> lazy(n * 4, 0);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	init(arr, segtree, 1, 0, n - 1);
	for (int i = 0; i < m + k; ++i) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update_range(segtree, lazy, 1, 0, n - 1, b - 1, c - 1, d);
		}
		if (a == 2) {
			cin >> b >> c;
			cout << find_sum(segtree, lazy, 1, 0, n - 1, b - 1, c - 1) << endl;
		}
	}
}