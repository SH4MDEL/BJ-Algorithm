#include <iostream>
#include <queue>
#include <tuple>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int n, m, ans, maxh;
bool visited[105][105];
int mountain[105][105];
constexpr int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
constexpr int dy[] = { -1, -1, -1, 0, 0, 1, 1 ,1 };

void bfs(int sy, int sx)
{
	queue<tuple<int, int, int>> q;
	visited[sy][sx] = true;
	q.push({ sy, sx, mountain[sy][sx] });

	while (!q.empty()) {
		auto [y, x, M] = q.front();
		q.pop();

		for (int i = 0; i < 8; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny == 0 || nx == 0 || ny == n + 1 || nx == m + 1 || 
				visited[ny][nx] || mountain[ny][nx] > M) continue;
			visited[ny][nx] = true;
			q.push({ ny, nx, mountain[ny][nx] });
		}
	}
	++ans;
}

int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> mountain[i][j];
			maxh = max(maxh, mountain[i][j]);
		}
	}
	for (int h = maxh; h >= 0; --h) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (!visited[i][j] && mountain[i][j] == h) bfs(i, j);
			}
		}
	}
	cout << ans;
}