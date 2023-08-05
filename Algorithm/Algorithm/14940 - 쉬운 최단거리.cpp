#include <iostream>
#include <queue>
#include <array>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int map[1010][1010];
int answer[1010][1010];
bool visited[1010][1010];
int n, m;
pair<int, int> start;

const array<int, 4> dx = { -1, 1, 0, 0 };
const array<int, 4> dy = { 0, 0, -1, 1 };

void bfs(int x, int y, int depth)
{

	queue<pair<pair<int, int>, int>> q;

	q.push({ { x, y }, depth });
	while (!q.empty()) {
		auto current = q.front(); q.pop();
		if (map[current.first.second][current.first.first] == 0 || 
			visited[current.first.second][current.first.first]) continue;
		answer[current.first.second][current.first.first] = current.second;
		visited[current.first.second][current.first.first] = true;

		for (int i = 0; i < 4; ++i) {
			if (!visited[current.first.second + dy[i]][current.first.first + dx[i]] &&
				current.first.second + dy[i] <= n && current.first.second + dy[i] >= 1 &&
				current.first.first + dx[i] <= m && current.first.first + dx[i] >= 1) {
				q.push({ { current.first.first + dx[i], current.first.second + dy[i] }, current.second + 1 });
			}
		}
	}

}

int main()
{
	fastip; sws;
	memset(visited, false, sizeof(bool) * 1010 * 1010);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				start.first = i;
				start.second = j;
			}
		}
	}

	bfs(start.second, start.first, 0);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (answer[i][j] == 0) {
				if (map[i][j] == 1) {
					answer[i][j] = -1;
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}
}