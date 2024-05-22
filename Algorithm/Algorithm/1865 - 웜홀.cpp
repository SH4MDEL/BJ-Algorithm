#include <iostream>
#include <string>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 10987654321
#define ll long long
#define endl "\n"
using namespace std;

int t, n, m, w;
vector<pair<int, int>> to[3000];
ll dist[550];
bool visited[550];

bool search(int start)
{
	visited[start] = true;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (const auto& [next, cost] : to[j]) {
				visited[next] = true;
				if (dist[next] > dist[j] + cost) {
					dist[next] = dist[j] + cost;
				}
			}
		}
	}
	for (int j = 1; j <= n; ++j) {
		for (const auto& [next, cost] : to[j]) {
			if (dist[next] > dist[j] + cost) {
				return true;
			}
		}
	}
	return false;
}

int main()
{
	fastip; sws;

	cin >> t;
	while (t--) {
		cin >> n >> m >> w;
		for (int i = 0; i < 3000; ++i) to[i].clear();
		for (int i = 0; i < 550; ++i) dist[i] = -1;
		for (int i = 0; i < 550; ++i) visited[i] = false;

		for (int i = 0; i < m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			to[a].push_back({ b, c });
			to[b].push_back({ a, c });
		}
		for (int i = 0; i < w; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			to[a].push_back({ b, -c });
		}
		int can = false;
		for (int i = 1; i <= n; ++i) {
			if (!visited[i]) {
				if (search(i)) {
					can = true;
					break;
				}
			}
		}
		if (can) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}