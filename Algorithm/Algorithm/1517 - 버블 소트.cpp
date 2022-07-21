#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
#define inf 1087654321
using namespace std;

struct Node {
	int value;
	int index;
};

Node merge(const Node& a, const Node& b)
{
	return {a.value + b.value, a.index + b.index};
}

Node init(Node input, vector<Node>& tree, int node, int start, int end)
{
	if (start == end) return tree[node] = {1, input.index};

	int mid = (start + end) / 2;
	if (start <= input.index && input.index <= mid) {
		init(input, tree, node * 2, start, mid);
	}
	if (mid + 1 <= input.index && input.index <= end) {
		init(input, tree, node * 2 + 1, mid + 1, end);
	}
	return tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

int find_sum(vector<Node>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) return tree[node].value;

	int mid = (start + end) / 2;
	return find_sum(tree, node * 2, start, mid, left, right) + find_sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);
	
	long long sum = 0;
	int n;
	cin >> n;
	vector<Node> arr(n);
	vector<Node> segtree(n * 4);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].value;
		arr[i].index = i;
	}
	sort(arr.begin(), arr.end(), [](const Node& a, const Node& b) {
		if (a.value == b.value) return a.index < b.index;
		return a.value < b.value;
		});
	for (int i = 0; i < n; ++i) {
		init(arr[i], segtree, 1, 0, n - 1);
		sum += find_sum(segtree, 1, 0, n - 1, arr[i].index + 1, n - 1);
	}
	cout << sum << endl;
}