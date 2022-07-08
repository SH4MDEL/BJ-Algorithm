#include <iostream>
#include <vector>
#define endl "\n"
#define inf 987654321
using namespace std;

int n, m, k;

long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	// 리프 노드 도착
	if (start == end) {
		return tree[node] = arr[start];
	}

	// 현재 노드의 값은 자식 노드 두 개의 합
	int mid = (start + end) / 2;
	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

long long find_sum(vector<long long>& tree, int node, int start, int end, int left, int right)
{
	// case 1: [start, end] 앞 뒤에 [left, right]가 없다.
	// 즉 교집합이 없기 때문에 더 탐색할 필요가 없다.
	if (left > end || right < start) return 0;

	// case 2: [left, right]가 [start, end]를 포함
	if (left <= start && end <= right) {
		return tree[node];
	}
	// case 3: [start, end]가 [left, right]를 포함하거나
	// case 4: [left, right]와 [start, end]가 겹쳐져 있는 경우
	int mid = (start + end) / 2;
	return find_sum(tree, node * 2, start, mid, left, right) + find_sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff)
{
	// diff는 업데이트된 수와 기존 수의 차이이다.
	if (index < start || index > end) return;
	tree[node] += diff;

	//루트노드가 아니라면
	if (start != end) {
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

int main()
{
	cin >> n >> m >> k;

	vector<long long> arr(n);
	vector<long long> segtree(n * 4);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	init(arr, segtree, 1, 0, n - 1);

	long long query, a, b;
	for (int i = 0; i < m + k; ++i) {
		cin >> query >> a >> b;
		if (query == 1) {
			long long diff = (long long)b - arr[a - 1];
			arr[a - 1] = b;
			update(segtree, 1, 0, n - 1, a - 1, diff);
		}
		if (query == 2) {
			cout << find_sum(segtree, 1, 0, n - 1, a - 1, b - 1) << endl;
		}
	}
}