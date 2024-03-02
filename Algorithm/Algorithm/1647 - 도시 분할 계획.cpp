#include <iostream>
#include <queue>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

struct vertex
{
	int a, b, v;

	bool operator<(const vertex& rhs) const {
		return v > rhs.v;
	}
};
priority_queue<vertex> pq;

int parent[100100];
int n, m;

int uf_find(int n)
{
	if (parent[n] == -1) return n;
	return parent[n] = uf_find(parent[n]);
}

bool uf_union(int a, int b)
{
	a = uf_find(a);
	b = uf_find(b);

	if (a == b) return false;
	parent[a] = b;
	return true;
}

int main()
{
	fastip; sws;

	fill(parent, parent + 100100, -1);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ a, b, c });
	}
	int count = 0, ans = 0;
	while (count != n - 2) {
		auto now = pq.top(); pq.pop();
		if (uf_union(now.a, now.b)) {
			ans += now.v;
			++count;
		}
	}
	cout << ans;
}