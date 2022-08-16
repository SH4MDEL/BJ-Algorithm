#include <iostream>
#include <vector>
#include <algorithm>
#define inf 987654321 
#define endl "\n"
using namespace std;

struct Vertex {
	int v, e, w;
};
int disjoint_set[10101];
int v, e;

int uf_find(int n) {
	if (disjoint_set[n] == -1) return n;
	return disjoint_set[n] = uf_find(disjoint_set[n]);
}

bool uf_union(int a, int b) {
	a = uf_find(a);
	b = uf_find(b);
	if (a == b) return false;
	disjoint_set[b] = a;
	return true;
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> v >> e;
	for (int i = 0; i < v; ++i) disjoint_set[i] = -1;

	int a, b, c;
	vector<Vertex> vertex(e);
	for (int i = 0; i < e; ++i) {
		cin >> a >> b >> c;
		vertex.push_back({ a, b, c });
	}
	sort(vertex.begin(), vertex.end(), [](const Vertex& a, const Vertex& b) {
		return a.w < b.w;
	});
	int ans = 0, cnt = 0;
	for (const auto& elm : vertex) {
		if (uf_union(elm.v, elm.e)) {
			ans += elm.w;
			++cnt;
		}
		if (cnt == v) break;
	}
	cout << ans << endl;
}