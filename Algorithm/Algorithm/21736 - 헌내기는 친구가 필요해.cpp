#include <iostream>
#include <tuple>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m, sy, sx, ans;
char field[610][610];
bool visited[610][610];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs()
{
	queue<tuple<int, int>> q;
	q.push({ sy, sx });
	visited[sy][sx] = true;

	while (!q.empty()) {
		auto [ny, nx] = q.front(); q.pop();

		for (int i = 0; i < 4; ++i) {
			int ty = ny + dy[i]; 
			int tx = nx + dx[i];
			if (!visited[ty][tx] && field[ty][tx] != 'X' &&
				ty != 0 && ty != n + 1 && tx != 0 && tx != m + 1) {
				if (field[ty][tx] == 'P') ++ans;
				visited[ty][tx] = true;
				q.push({ ty, tx });
			}
		}
	}
	return ans;
}

int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> field[i][j];
			if (field[i][j] == 'I') {
				sy = i; sx = j;
			}
		}
	}
	bfs();
	if (ans) cout << ans;
	else cout << "TT";
}