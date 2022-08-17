#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;
int disjoint_set[500500];


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
	fastip; sws;

	cin >> n >> m;
	int a, b;
	for (int i = 0; i <= n; ++i) {
		disjoint_set[i] = -1;
	}
	bool ans = false;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		if (!uf_union(a, b)) {
			ans = true;
			cout << i + 1 << endl;
			break;
		}
	}
	if (!ans) cout << 0 << endl;
}