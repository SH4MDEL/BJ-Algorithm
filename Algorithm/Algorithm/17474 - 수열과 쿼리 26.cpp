#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
#define inf 10'987'654'321
using namespace std;

struct Node {
	long long maxval;	// ��������� ��� ����� ��. �� �ܿ��� �������� ���� ū ��.
	long long smaxval;	// �������� �� ��°�� ū ��
	long long cnt;		// �������� maxval�� ���� ���� ���� ����� ��
	long long sum;		// ������
};

Node merge(Node a, Node b)
{
	if (a.maxval == b.maxval) return { a.maxval, max(a.smaxval, b.smaxval), a.cnt + b.cnt, a.sum + b.sum };
	if (a.maxval > b.maxval) return { a.maxval, max(a.smaxval, b.maxval), a.cnt, a.sum + b.sum };
	return { b.maxval, max(a.maxval, b.smaxval), b.cnt, a.sum + b.sum };
}

Node init(vector<long long>& arr, vector<Node>& tree, int node, int start, int end)
{
	if (start == end) return tree[node] = { arr[start], -1, 1, arr[start] };

	int mid = (start + end) / 2;
	return tree[node] = merge(init(arr, tree, node * 2, start, mid), init(arr, tree, node * 2 + 1, mid + 1, end));
}

void update_lazy(vector<Node>& tree, int node, int start, int end)
{
	if (start == end) return;
	if (tree[node].maxval < tree[node * 2].maxval) {
		tree[node * 2].sum -= (tree[node * 2].maxval - tree[node].maxval) * tree[node * 2].cnt;
		tree[node * 2].maxval = tree[node].maxval;
	}
	if (tree[node].maxval < tree[node * 2 + 1].maxval) {
		tree[node * 2 + 1].sum -= (tree[node * 2 + 1].maxval - tree[node].maxval) * tree[node * 2 + 1].cnt;
		tree[node * 2 + 1].maxval = tree[node].maxval;
	}
}

void update_range(vector<Node>& tree, int node, int start, int end, int left, int right, int val)
{
	update_lazy(tree, node, start, end);
	// ���� �������� ���� ū ������ val�� �� ũ�ٸ� 
	// ���� �Ʒ��δ� ���ŵ� ���� ������ ����ġ���Ѵ�.
	if (left > end || right < start || tree[node].maxval <= val) return;

	// �������� ���� ū ������ val�� ������ �ڸ��ϴ�. (�� ���� ���� ��� �� ���� ���ŵȴ�)
	// �� �� �������� �� ��°�� ū ������ val�� ũ�ٸ� ��� ����� �ּڰ��� �����ؾ� �Ѵ�.
	if (left <= start && end <= right && tree[node].smaxval < val) {
		tree[node].sum -= (tree[node].maxval - val) * tree[node].cnt;
		tree[node].maxval = val;
		return;
	}

	// �� �ܿ��� case�� ���� ����Ѵ�.
	int mid = (start + end) / 2;
	update_range(tree, node * 2, start, mid, left, right, val);
	update_range(tree, node * 2 + 1, mid + 1, end, left, right, val);
	tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

long long find_sum(vector<Node>& tree, int node, int start, int end, int left, int right)
{
	update_lazy(tree, node, start, end);
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) {
		return tree[node].sum;
	}
	int mid = (start + end) / 2;
	return find_sum(tree, node * 2, start, mid, left, right) + find_sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

long long find_max(vector<Node>& tree, int node, int start, int end, int left, int right)
{
	update_lazy(tree, node, start, end);
	if (left > end || right < start) return -1;

	if (left <= start && end <= right) {
		return tree[node].maxval;
	}
	int mid = (start + end) / 2;
	return max(find_max(tree, node * 2, start, mid, left, right), find_max(tree, node * 2 + 1, mid + 1, end, left, right));
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	int n, m;
	cin >> n;
	vector<long long> arr(n);
	vector<Node> segtree(n * 4);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	init(arr, segtree, 1, 0, n - 1);
	cin >> m;
	int q, a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> q;
		if (q == 1) {
			cin >> a >> b >> c;
			update_range(segtree, 1, 0, n - 1, a - 1, b - 1, c);
		}
		if (q == 2) {
			cin >> a >> b;
			cout << find_max(segtree, 1, 0, n - 1, a - 1, b - 1) << endl;
		}
		if (q == 3) {
			cin >> a >> b;
			cout << find_sum(segtree, 1, 0, n - 1, a - 1, b - 1) << endl;
		}
	}
}