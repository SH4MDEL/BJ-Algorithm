#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;
struct Node {
	int v, e, w;
};
vector<Node> vertex;

int disjoint_set[200200];

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

	while (true) {
		cin >> m >> n;
		if (m == 0 || n == 0) break;
		for (int i = 0; i < n; ++i) {
			disjoint_set[i] = -1;
		}
		vertex.clear();
		int a, b, c, sumw = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b >> c;
			sumw += c;
			vertex.push_back({ a, b, c });
		}
		sort(vertex.begin(), vertex.end(), [](const Node& a, const Node& b) {
			return a.w < b.w;
			});
		int cnt = 0, sum = 0;
		for (int i = 0; i < n; ++i) {
			if (uf_union(vertex[i].v, vertex[i].e)) {
				sum += vertex[i].w;
				++cnt;
			}
			if (cnt == m - 1) break;
		}
		cout << sumw - sum << endl;
	}
}