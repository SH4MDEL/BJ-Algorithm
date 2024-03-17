#include <iostream>
#include <optional>
#include <vector>
#include <tuple>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int m, n, h;
vector field(110, vector(110, vector(110, 0)));
vector visited(110, vector(110, vector(110, optional<int>())));

typedef tuple<int, int, int> pos;

constexpr int dx[] = { -1, 1, 0, 0, 0, 0 };
constexpr int dy[] = { 0, 0, -1, 1, 0, 0 };
constexpr int dz[] = { 0, 0, 0, 0, -1, 1 };

int bfs()
{
	queue<pos> q;
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= m; ++k) {
				if (field[i][j][k] == 1) {
					q.push({ i, j, k });
					visited[i][j][k].emplace(0);
				}
			}
		}
	}
	while (!q.empty()) {
		auto [nz, ny, nx] = q.front(); q.pop();
		auto day = visited[nz][ny][nx].value();
		for (int i = 0; i < 6; ++i) {
			auto tz = nz + dz[i];
			auto ty = ny + dy[i];
			auto tx = nx + dx[i];
			if (!visited[tz][ty][tx].has_value() && field[tz][ty][tx] != -1 &&
				tx != 0 && tx != m + 1 && ty != 0 && ty != n + 1 && tz != 0 && tz != h + 1) {
				q.push({ tz, ty, tx });
				visited[tz][ty][tx].emplace(day + 1);
				field[tz][ty][tx] = 1;
			}
		}
	}

	int ans = -1;
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= m; ++k) {
				if (!field[i][j][k]) return -1;
				if (visited[i][j][k].has_value()) {
					ans = max(ans, visited[i][j][k].value());
				}
			}
		}
	}
	return ans;
}

int main()
{
	fastip; sws;

	cin >> m >> n >> h;
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= m; ++k) {
				cin >> field[i][j][k];
			}
		}
	}
	cout << bfs();
}