#include <iostream>
#include <ranges>
#include <memory.h>
#include <tuple>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int t, n;
bool isUnion[3030][3030];
typedef tuple<int, int, int> Coord;
int disjoint_set[3030];

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
	cin >> t;
	while (t--) {
		memset(isUnion, false, sizeof isUnion);
		memset(disjoint_set, -1, sizeof disjoint_set);
		vector<Coord> v;
		cin >> n;
		int ans = n;
		for (const auto& i : views::iota(0, n)) {
			int x, y, r;
			cin >> x >> y >> r;
			v.push_back({ x, y, r });
		}
		for (const auto& i : views::iota(0, n)) {
			for (const auto& j : views::iota(i + 1, n)) {
				auto [x1, y1, r1] = v[i];
				auto [x2, y2, r2] = v[j];
				if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 + r2) * (r1 + r2)) {
					if (uf_union(i, j)) {
						--ans;
					}
				}
			}
		}
		cout << ans << endl;
	}
}