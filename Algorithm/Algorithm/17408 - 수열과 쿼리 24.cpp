#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

struct Node {
	int first, second;
};

Node merge(const Node& a, const Node& b)
{
	if (a.first > b.first) {
		return { a.first, max(a.second, b.first) };
	}
	if (a.first < b.first) {
		return { b.first, max(a.first, b.second) };
	}
	return { a.first, b.first };
}

Node init(vector<int>& arr, vector<Node>& tree, int node, int start, int end)
{
	if (start == end) return tree[node] = { arr[start], -1 };

	int mid = (start + end) / 2;
	return tree[node] = merge(init(arr, tree, node * 2, start, mid), init(arr, tree, node * 2 + 1, mid + 1, end));
}

Node update(vector<int>& arr, vector<Node>& tree, int node, int start, int end, int index)
{
	if (start > index || index > end) return tree[node];
	if (start == end) return tree[node] = { arr[start], -1 };

	int mid = (start + end) / 2;
	return tree[node] = merge(update(arr, tree, node * 2, start, mid, index), update(arr, tree, node * 2 + 1, mid + 1, end, index));
}

Node find_num(vector<Node>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return { -1, -1 };

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return merge(find_num(tree, node * 2, start, mid, left, right), find_num(tree, node * 2 + 1, mid + 1, end, left, right));
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n;
	vector<int> arr(n);
	vector<Node> segtree(n * 4);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	init(arr, segtree, 1, 0, n - 1);
	cin >> m;
	int q, a, b;
	for (int i = 0; i < m; ++i) {
		cin >> q >> a >> b;
		if (q == 1) {
			arr[a - 1] = b;
			update(arr, segtree, 1, 0, n - 1, a - 1);
		}
		if (q == 2) {
			Node answer = find_num(segtree, 1, 0, n - 1, a - 1, b - 1);
			cout << answer.first + answer.second << endl;
		}
	}
}