#include <iostream>
#include <vector>
#include <algorithm>
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m, k, sum_cost;
int cost[10101];
int disjoint_set[10101];
int min_cost[10101];

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

	cin >> n >> m >> k;
	for (int i = 0; i <= n; ++i) {
		disjoint_set[i] = -1;
	}
	for (int i = 0; i <= n; ++i) {
		min_cost[i] = inf;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> cost[i];
	}
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		uf_union(a, b);
	}
	for (int i = 1; i <= n; ++i) {
		if (min_cost[uf_find(i)] > cost[i]) {
			min_cost[uf_find(i)] = cost[i];
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (min_cost[i] != inf) {
			sum_cost += min_cost[i];
		}
	}
	if (sum_cost > k) {
		cout << "Oh no" << endl;
	}
	else {
		cout << sum_cost << endl;
	}
}