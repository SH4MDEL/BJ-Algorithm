#include <iostream>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int n, m;
struct Bh {
	ll b, p = -inf;

	bool operator<(const Bh& rhs) const { return b < rhs.b; }
};
Bh bh[200200];
struct Aster {
	ll a, w;

	bool operator<(const Aster& rhs) const { return a < rhs.a; }
};
Aster ast[200200];

int main()
{
	fastip; sws;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> bh[i].b;
	for (int i = 0; i < m; ++i) cin >> ast[i].a >> ast[i].w;
	bh[n].b = inf;
	bh[n + 1].b = -inf;

	sort(bh, bh + n + 2); sort(ast, ast + m);

	int lb = 0, rb = 1;
	for (int i = 0; i < m; ++i) {
		while (!(bh[lb].b < ast[i].a && bh[rb].b > ast[i].a)) {
			++lb, ++rb;
		}

		ll lp = (ast[i].a - bh[lb].b) * ast[i].w;
		ll rp = (bh[rb].b - ast[i].a) * ast[i].w;
		if (bh[lb].p < lp && bh[rb].p < rp) {
			if (lp < rp) bh[lb].p = lp;
			else bh[rb].p = rp;
		}
	}
	ll maximum = -inf;
	for (int i = 1; i <= n; ++i) {
		maximum = max(maximum, bh[i].p);
	}
	cout << maximum << endl;
}