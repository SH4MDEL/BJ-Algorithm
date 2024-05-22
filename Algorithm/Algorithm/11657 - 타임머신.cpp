#include <iostream>
#include <string>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

ll n, m, ans[550];
vector<pair<int, int>> to[550];

int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 0; i <= n; ++i) ans[i] = inf;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		to[a].push_back({ b, c });
	}
	ans[1] = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (const auto& [next, cost] : to[j]) {
				if (ans[j] != inf && ans[next] > ans[j] + cost) {
					ans[next] = ans[j] + cost;
				}
			}
		}
	}

	for (int j = 1; j <= n; ++j) {
		for (const auto& [next, cost] : to[j]) {
			if (ans[j] != inf && ans[next] > ans[j] + cost) {
				cout << -1;
				return 0;
			}
		}
	}
	for (int i = 2; i <= n; ++i) {
		if (ans[i] == inf) cout << -1 << endl;
		else cout << ans[i] << endl;
	}
}