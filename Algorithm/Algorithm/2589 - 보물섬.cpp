#include <iostream>
#include <queue>
#include <tuple>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int n, m, ans;
char field[55][55];
bool visited[55][55];
constexpr int dx[] = { 0, 1, 0, -1 };
constexpr int dy[] = { 1, 0, -1, 0 };

void bfs(int sy, int sx)
{
	memset(visited, false, sizeof visited);

	queue<tuple<int, int, int>> q;
	q.push({ sy, sx, 1 });
	visited[sy][sx] = true;
	while (!q.empty()) {
		auto [y, x, cost] = q.front(); q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny == 0 || ny == n + 1 || nx == 0 || nx == m + 1 || 
				visited[ny][nx] || field[ny][nx] == 'W') {
				continue;
			}
			ans = max(ans, cost);
			q.push({ ny, nx, cost + 1});
			visited[ny][nx] = true;
		}
	}
}

int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> field[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (field[i][j] == 'L') bfs(i, j);
		}
	}
	cout << ans;
}