#include <iostream>
#include <memory.h>
#include <tuple>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define mod 1'000'000'000
#define ll long long
#define endl "\n"
using namespace std;

int n, m, t, ans;
bool visited[110][110][2];
int castle[110][110];
constexpr int dx[] = { 0, 1, 0, -1 };
constexpr int dy[] = { 1, 0, -1, 0 };

bool bfs()
{
	queue<tuple<int, int, int, bool>> q;
	q.push({ 1, 1, 0, false });
	visited[1][1][0] = true;

	while (!q.empty()) {
		auto [y, x, time, gram] = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny == 0 || ny == n + 1 || nx == 0 || nx == m + 1 || 
				visited[ny][nx][gram] || (castle[ny][nx] == 1 && !gram)) continue;
			
			if (ny == n && nx == m) {
				ans = time + 1;
				return true;
			}
			if (time + 1 == t) continue;
			if (castle[ny][nx] == 2) {
				q.push({ ny, nx, time + 1, true });
				visited[ny][nx][1] = visited[ny][nx][0] = true;
				continue;
			}
			q.push({ ny, nx, time + 1, gram });
			if (gram) visited[ny][nx][1] = true;
			visited[ny][nx][0] = true;
		}
	}
	return false;
}

int main()
{
	fastip; sws;

	cin >> n >> m >> t;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> castle[i][j];
		}
	}
	if (bfs()) cout << ans;
	else cout << "Fail";
}