#include <iostream>
#include <queue>
#include <stack>
#include <array>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"

using namespace std;

int map[1010][1010];
queue<pair<pair<int, int>, int>> q;

int m, n, maxNum;

void bfs()
{
	while (!q.empty())
	{
		auto now = q.front(); q.pop();

		const array<int, 4> dx = { 1, -1, 0, 0 };
		const array<int, 4> dy = { 0, 0, 1, -1 };
		for (int i = 0; i < 4; ++i) {
			if (map[now.first.first + dy[i]][now.first.second + dx[i]] ||
				now.first.first + dy[i] < 1 || now.first.first + dy[i] > n ||
				now.first.second + dx[i] < 1 || now.first.second + dx[i] > m) continue;
			map[now.first.first + dy[i]][now.first.second + dx[i]] = now.second + 1;
			q.push({ {now.first.first + dy[i], now.first.second + dx[i]}, now.second + 1});
		}
	}
}

int main()
{
	fastip; sws;

	cin >> m >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1) q.push({{i, j}, 1});
		}
	}
	bfs();

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!map[i][j]) {
				cout << -1;
				return 0;
			}
			maxNum = max(maxNum, map[i][j]);
		}
	}
	cout << maxNum - 1;
}