#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

struct Node {
	int l, r, all, maxi;

	int find_all() {
		return all;
	};
	int find_left() {
		return max(l, all);
	}
	int find_right() {
		return max(r, all);
	}
	int find_max() {
		return max(find_left(), find_right());
	}
};

Node init(vector<int>& arr, vector<Node>& tree, int node, int start, int end)
{
	if (start == end) return tree[node] = { arr[start], arr[start], arr[start], arr[start] };

	int mid = (start + end) / 2;
	Node leftnode, rightnode, mainnode;
	leftnode = init(arr, tree, node * 2, start, mid);
	rightnode = init(arr, tree, node * 2 + 1, mid + 1, end);
	mainnode.all = leftnode.find_all() + rightnode.find_all();
	mainnode.l = max(leftnode.find_all() + rightnode.find_left(), leftnode.find_left());
	mainnode.r = max(leftnode.find_right() + rightnode.find_all(), rightnode.find_right());
	return tree[node] = mainnode;
}

Node find_sum(vector<Node>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return { -inf, -inf, -inf };

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	Node mainnode;
	Node leftnode = find_sum(tree, node * 2, start, mid, left, right);
	Node rightnode = find_sum(tree, node * 2 + 1, mid + 1, end, left, right);
	if (leftnode.all != -inf && rightnode.all != -inf) {
		mainnode.all = leftnode.find_all() + rightnode.find_all();
		mainnode.l = max(leftnode.find_all() + rightnode.find_left(), leftnode.find_left());
		mainnode.r = max(leftnode.find_right() + rightnode.find_all(), rightnode.find_right());
		return mainnode;
	}
	if (leftnode.all == -inf) return rightnode;
	return leftnode;
}

int main()
{
	int n, m;
	cin >> n;
	vector<int> arr(n);
	vector<Node> segtree(n * 4);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	init(arr, segtree, 1, 0, n - 1);
	cin >> m;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		cout << find_sum(segtree, 1, 0, n - 1, a - 1, b - 1).find_max() << endl;
	}
}