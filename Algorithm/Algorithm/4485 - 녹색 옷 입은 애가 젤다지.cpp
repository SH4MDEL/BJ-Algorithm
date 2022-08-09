#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
#define inf 987'654'321
using namespace std;

int map[130][130];
int dist[130][130];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n, counter;

void dijkstra()
{
	queue<pair<int, int>> q;
	dist[1][1] = map[1][1];
	q.push({ 1, 1 });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			if (ty > n || ty < 1 || tx > n || tx < 1) continue;

			if (dist[ty][tx] > dist[y][x] + map[ty][tx]) {
				dist[ty][tx] = dist[y][x] + map[ty][tx];
				q.push({ ty, tx });
			}
		}
	}
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	while (1) {
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < 130; ++i) {
			for (int j = 0; j < 130; ++j) {
				dist[i][j] = inf;
			}
		}
		for (int i = 0; i < 130; ++i) {
			for (int j = 0; j < 130; ++j) {
				map[i][j] = inf;
			}
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> map[i][j];
			}
		}

		dijkstra();

		cout << "Problem " << ++counter << ": " << dist[n][n] << endl;
		//for (int i = 1; i <= n; ++i) {
		//	for (int j = 1; j <= n; ++j) {
		//		cout << dist[i][j] << " ";
		//	}
		//	cout << endl;
		//}
	}

}