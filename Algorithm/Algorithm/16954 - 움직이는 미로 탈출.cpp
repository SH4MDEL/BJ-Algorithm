#include <iostream>
#include <ranges>
#include <queue>
#include <tuple>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

char field[10][10][10];
bool visited[10][10][10];
queue<tuple<int, int, int>> q;
constexpr int dx[] = { 0, -1, 0, 1, 1, 1, 0, -1, -1 };
constexpr int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1, 0 };

int bfs()
{
	q.push({ 8, 1, -1 });
	while (!q.empty()) {
		auto [ny, nx, time] = q.front(); q.pop();
		int tt = (time == 8 ? 8 : time + 1);
		if (field[ny][nx][tt] == '#') continue;
		for (const auto& i : views::iota(0, 9)) {
			int ty = ny + dy[i];
			int tx = nx + dx[i];
			if (ty >= 1 && ty <= 8 && tx >= 1 && tx <= 8 &&
				!visited[ty][tx][tt] && field[ty][tx][tt] != '#') {
				if (ty == 1 && tx == 8) return 1;
				visited[ty][tx][tt] = true;
				q.push({ ty, tx, tt });
			}
		}
	}

	return 0;
}

int main()
{
	fastip; sws;

	for (const auto& i : views::iota(1, 9)) {
		for (const auto& j : views::iota(1, 9)) {
			cin >> field[i][j][0];
		}
	}
	for (const auto& t : views::iota(1, 9)) {
		for (const auto& i : views::iota(1, 9)) {
			for (const auto& j : views::iota(1, 9)) {
				if (t >= i) field[i][j][t] = '.';
				else field[i][j][t] = field[i - 1][j][t - 1];
			}
		}
	}

	cout << bfs();
}