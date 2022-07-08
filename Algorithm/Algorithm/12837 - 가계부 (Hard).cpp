#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

int n, q;

void update(vector<long long>& segtree, int node, int start, int end, int index, long long diff)
{
	if (index < start || index > end) return;
	segtree[node] += diff;

	if (start != end) {
		int mid = (start + end) / 2;
		update(segtree, node * 2, start, mid, index, diff);
		update(segtree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

long long find(vector<long long>& segtree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;

	if (left <= start && right >= end) return segtree[node];

	int mid = (start + end) / 2;
	return find(segtree, node * 2, start, mid, left, right) + find(segtree, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n >> q;

	vector<long long> arr(n);
	vector<long long> segtree(n * 4);

	int query, a, b;
	for (int i = 0; i < q; ++i) {
		cin >> query >> a >> b;
		if (query == 1) {
			arr[a - 1] += b;
			update(segtree, 1, 0, n - 1, a - 1, b);
		}
		if (query == 2) {
			cout << find(segtree, 1, 0, n - 1, a - 1, b - 1) << endl;
		}
	}
}