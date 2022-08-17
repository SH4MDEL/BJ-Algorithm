#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;
int disjoint_set[101010];
struct Node {
	int v, e, w;
};
vector<Node> vertex;

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
	fastip; sws;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		disjoint_set[i] = -1;
	}
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		vertex.push_back({ a, b, c });
	}
	sort(vertex.begin(), vertex.end(), [](const Node& a, const Node& b) {
		return a.w < b.w;
		});
	int ans = 0, cnt = 0;
	for (const auto& elm : vertex) {
		if (uf_union(elm.v, elm.e)) {
			ans += elm.w;
			++cnt;
		}
		if (cnt == n) break;
	}
	cout << ans << endl;
}