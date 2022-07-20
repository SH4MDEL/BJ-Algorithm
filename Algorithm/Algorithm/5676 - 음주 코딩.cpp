#include <iostream>
#include <vector>
#define endl "\n"
#define inf 987654321
using namespace std;

int init(vector<int>& arr, vector<int>& tree, int node, int start, int end)
{
	if (start == end) {
		if (arr[start] > 0) return tree[node] = 1;
		if (arr[start] < 0) return tree[node] = -1;
		return tree[node] = 0;
	}
	int mid = (start + end) / 2;
	return tree[node] = init(arr, tree, node * 2, start, mid) * init(arr, tree, node * 2 + 1, mid + 1, end);
}

void update(vector<int>& arr, vector<int>& tree, int node, int start, int end, int index)
{
	if (index > end || index < start) return;
	if (start == end) {
		if (arr[start] > 0) {
			tree[node] = 1;
			return;
		}
		if (arr[start] < 0) {
			tree[node] = -1;
			return;
		}
		tree[node] = 0;
		return;
	}
	int mid = (start + end) / 2;
	update(arr, tree, node * 2, start, mid, index);
	update(arr, tree, node * 2 + 1, mid + 1, end, index);
	tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int find(vector<int>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 1;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return find(tree, node * 2, start, mid, left, right) * find(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	int n, m;
	while (cin >> n >> m) {
		vector<int> arr(n);
		vector<int> segtree(n * 4);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		init(arr, segtree, 1, 0, n - 1);

		char query; 
		int a, b;
		string ansstring = "";
		for (int i = 0; i < m; ++i) {
			cin >> query >> a >> b;
			if (query == 'P') {
				int answer = find(segtree, 1, 0, n - 1, a - 1, b - 1);
				if (answer > 0) {
					ansstring += "+";
				}
				if (answer < 0) {
					ansstring += "-";
				}
				if (answer == 0) {
					ansstring += "0";
				}
			}
			if (query == 'C') {
				arr[a - 1] = b;
				update(arr, segtree, 1, 0, n - 1, a - 1);
			}
		}
		cout << ansstring << endl;
	}
}