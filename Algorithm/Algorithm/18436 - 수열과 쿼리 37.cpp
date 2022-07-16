#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

// 짝수 개수 저장
int init(vector<int>& arr, vector<int>& tree, int node, int start, int end)
{
	if (start == end) {
		if ((arr[start] % 2) == 1) {
			return tree[node] = 0;
		}
		if ((arr[start] % 2) == 0) {
			return tree[node] = 1;
		}
	}

	int mid = (start + end) / 2;

	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

void update(vector<int>& tree, int node, int start, int end, int index, int diff)
{
	if (index > end || index < start) return;

	if ((diff % 2) == 1) {
		tree[node] -= 1;
	}
	if ((diff % 2) == 0) {
		tree[node] += 1;
	}

	if (start != end) {
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

int find(vector<int>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return find(tree, node * 2, start, mid, left, right) + find(tree, node * 2 + 1, mid + 1, end, left, right);
}

int n, m, query, a, b;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n;
	vector<int> arr(n);
	vector<int> segtree(n * 4);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	init(arr, segtree, 1, 0, n - 1);
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> query >> a >> b;
		if (query == 1) {
			if ((arr[a - 1] - b) % 2 == 0) {
				arr[a - 1] = b;
			}
			if ((arr[a - 1] - b) % 2 == 1 || (arr[a - 1] - b) % 2 == -1) {
				arr[a - 1] = b;
				update(segtree, 1, 0, n - 1, a - 1, b);
			}
		}
		if (query == 2) {
			cout << find(segtree, 1, 0, n - 1, a - 1, b - 1) << endl;
		}
		if (query == 3) {
			cout << b - a + 1 - find(segtree, 1, 0, n - 1, a - 1, b - 1) << endl;
		}
	}
}