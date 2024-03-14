#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

struct vertex
{
	int x, y, z;
	int index;
};

vector<vertex> a, b, c;
int n;

struct edge
{
	int s, e, v;

	bool operator<(const edge& rhs) const {
		return v > rhs.v;
	}
};
priority_queue<edge> pq;

int disjoint_set[101010];

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

	cin >> n;
	for (int i = 0; i < n; ++i) {
		vertex v;
		v.index = i;
		cin >> v.x >> v.y >> v.z;
		a.push_back(v);
		b.push_back(v);
		c.push_back(v);
	}
	sort(a.begin(), a.end(), [](const vertex& i, const vertex& j) {
		return i.x < j.x; });
	sort(b.begin(), b.end(), [](const vertex& i, const vertex& j) {
		return i.y < j.y; });
	sort(c.begin(), c.end(), [](const vertex& i, const vertex& j) {
		return i.z < j.z; });

	for (int i = 0; i < n - 1; ++i) {
		pq.push({ a[i].index, a[i + 1].index, abs(a[i].x - a[i + 1].x) });
		pq.push({ b[i].index, b[i + 1].index, abs(b[i].y - b[i + 1].y) });
		pq.push({ c[i].index, c[i + 1].index, abs(c[i].z - c[i + 1].z) });
	}

	fill(disjoint_set, disjoint_set + 101010, -1);

	int count = 0;
	int ans = 0;
	while (count != n - 1) {
		auto now = pq.top(); pq.pop();
		if (uf_union(now.s, now.e)) {
			ans += now.v;
			++count;
		}
	}
	cout << ans;
}