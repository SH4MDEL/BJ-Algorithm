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
	for (int i = 0; i < n; ++i) {
		disjoint_set[i] = -1;
	}
	int query, a, b;
	for (int i = 0; i < m; ++i) {
		cin >> query >> a >> b;
		if (query == 0) {
			uf_union(a, b);
		}
		if (query == 1) {
			if (uf_find(a) == uf_find(b)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}