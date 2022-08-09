#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
#define inf 987'654'321
using namespace std;

int n, m;
int dist[110][110];
int map[110][110];

void dijkstra(int x, int y)
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(y, x));
	dist[y][x] = 0;

	while (!pq.empty()) {
		int y = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (y < n && dist[y + 1][x] > dist[y][x] + map[y + 1][x]) {
			dist[y + 1][x] = dist[y][x] + map[y + 1][x];
			pq.push(make_pair(y + 1, x));
		}
		if (y > 1 && dist[y - 1][x] > dist[y][x] + map[y - 1][x]) {
			dist[y - 1][x] = dist[y][x] + map[y - 1][x];
			pq.push(make_pair(y - 1, x));
		}
		if (x < m && dist[y][x + 1] > dist[y][x] + map[y][x + 1]) {
			dist[y][x + 1] = dist[y][x] + map[y][x + 1];
			pq.push(make_pair(y, x + 1));
		}
		if (x > 1 && dist[y][x - 1] > dist[y][x] + map[y][x - 1]) {
			dist[y][x - 1] = dist[y][x] + map[y][x - 1];
			pq.push(make_pair(y, x - 1));
		}
	}
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> m >> n;
	char inp;
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= m + 1; ++j) {
			map[i][j] = inf;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> inp;
			map[i][j] = inp - '0';
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			dist[i][j] = inf;
		}
	}
	dijkstra(1, 1);
	cout << dist[n][m] << endl;
}