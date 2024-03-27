#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

int n, m;

struct Astro {
	int v, i;
	bool operator==(const Astro& rhs) const {
		return (v == rhs.v && i == rhs.i);
	}
	bool operator<(const Astro& rhs) const {
		return v < rhs.v;
	}
};

vector<Astro> astro[105];

int main()
{
	fastip; sws;

	cin >> m >> n;
	for (int i = 0; i < m; ++i) {
		astro[i].resize(n);
		for (int j = 0; j < n; ++j) {
			cin >> astro[i][j].v;
			astro[i][j].i = j;
		}
	}
	for (int i = 0; i < m; ++i) {
		sort(astro[i].begin(), astro[i].end());
		int prev = astro[i][0].v;
		int now = 0;
		astro[i][0].v = now;
		for (int j = 1; j < n; ++j) {
			if (astro[i][j].v != prev) {
				prev = astro[i][j].v;
				astro[i][j].v = ++now;
			}
			else {
				astro[i][j].v = now;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			if (astro[i] == astro[j]) ++ans;
		}
	}
	cout << ans;
}