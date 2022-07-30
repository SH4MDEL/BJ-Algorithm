#include <iostream>
#include <vector>
#define endl "\n"
#define inf 987654321
#define mod 1'000'000'007
using namespace std;

struct Lazy {
	long long a, b;
	Lazy() { a = 1, b = 0; }
	void reset() {
		a = 1, b = 0;
	}
};

long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	if (start == end) tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = (init(arr, tree, node * 2, start, mid) % mod + init(arr, tree, node * 2, mid + 1, end) % mod) % mod;
}

long long update_lazy(vector<long long>& tree, vector<Lazy>& lazy, int node, int start, int end)
{
	if (lazy[node].a != 1 || lazy[node].b != 0) {

	}
}