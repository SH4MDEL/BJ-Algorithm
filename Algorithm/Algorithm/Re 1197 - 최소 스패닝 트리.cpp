#include <iostream>
#include <queue>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int v, e;
int disjoint_set[10010];

struct vertex {
	int s, e, v;

	bool operator<(const vertex& rhs) const {
		return v > rhs.v;
	}
};
priority_queue<vertex> pq;

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
	disjoint_set[a] = b;
	return true;
}

int main()
{
	fastip; sws;

	fill(disjoint_set, disjoint_set + 10010, -1);

	cin >> v >> e;
	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({a, b, c});
	}
	int count = 0, ans = 0;
	while (count != v - 1) {
		auto now = pq.top(); pq.pop();
		if (uf_union(now.s, now.e)) {
			ans += now.v;
			++count;
		}
	}
	cout << ans;
}