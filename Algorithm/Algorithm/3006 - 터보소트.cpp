#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

int n;

int init(vector<int>& tree, int node, int start, int end)
{
	if (start == end) return tree[node] = 1;

	int mid = (start + end) / 2;
	return tree[node] = init(tree, node * 2, start, mid) + init(tree, node * 2 + 1, mid + 1, end);
}

int find(vector<int>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;

	if (left <= start && right >= end) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return find(tree, node * 2, start, mid, left, right) + find(tree, node * 2 + 1, mid + 1, end, left, right);
}

void update(vector<int>& tree, int node, int start, int end, int index)
{
	if (index < start || index > end) return;

	tree[node] -= 1;

	if (start != end) {
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index);
		update(tree, node * 2 + 1, mid + 1, end, index);
	}
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n;
	vector<int> arr(n);
	vector<int> segtree(n * 4);
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		arr[num - 1] = i;
	}
	init(segtree, 1, 0, n - 1);

	for (int i = 0; i < n / 2; ++i) {
		cout << find(segtree, 1, 0, n - 1, 0, arr[i]) - 1 << endl;
		update(segtree, 1, 0, n - 1, arr[i]);

		cout << find(segtree, 1, 0, n - 1, arr[n - (i + 1)], n - 1) - 1 << endl;
		update(segtree, 1, 0, n - 1, arr[n - (i + 1)]);

	}
	if (n % 2 == 1) {
		cout << "0" << endl;
		//update(segtree, 1, 0, n - 1, arr[n / 2] - 1);
	}
}