#include <iostream>
#include <vector>
#include <algorithm>
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;
int disjoint_set[1000010];

int uf_find(int n)
{
	if (disjoint_set[n] == -1) return n;
	return disjoint_set[n] = uf_find(disjoint_set[n]);
}

bool uf_union(int a, int b)
{
	a = uf_find(a);
	b = uf_find(b);
	if (a == b) return false;
	disjoint_set[b] = a;
	return true;
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i <= n; ++i) disjoint_set[i] = -1;
	int a;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a;
			if (a == 1) uf_union(i, j);
		}
	}
	int root;
	bool checker = true;
	cin >> a;
	root = uf_find(a - 1);
	for (int i = 1; i < m; ++i) {
		cin >> a;
		if (uf_find(a - 1) != root) checker = false;
	}
	if (checker) cout << "YES" << endl;
	else cout << "NO" << endl;
}