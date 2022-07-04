#include <iostream>
#include <queue>
#define endl "\n"
#define inf 987654321
using namespace std;

bool map[105][105];
int visited[105][105];
int n, m;

queue<pair<int, int>> q;

void bfs(int x, int y)
{
	q.push(make_pair(x, y));
	visited[y][x] = 1;

	[&]() {
		while (!q.empty()) {
			int qsize = q.size();

			for (int i = 0; i < qsize; ++i) {
				pair<int, int> current = q.front();
				q.pop();

				if (map[current.second - 1][current.first] && visited[current.second - 1][current.first] == -1) {
					q.push(make_pair(current.first, current.second - 1));
					visited[current.second - 1][current.first] = visited[current.second][current.first] + 1;
				}
				if (map[current.second + 1][current.first] && visited[current.second + 1][current.first] == -1) {
					q.push(make_pair(current.first, current.second + 1));
					visited[current.second + 1][current.first] = visited[current.second][current.first] + 1;
				}
				if (map[current.second][current.first - 1] && visited[current.second][current.first - 1] == -1) {
					q.push(make_pair(current.first - 1, current.second));
					visited[current.second][current.first - 1] = visited[current.second][current.first] + 1;
				}
				if (map[current.second][current.first + 1] && visited[current.second][current.first + 1] == -1) {
					q.push(make_pair(current.first + 1, current.second));
					visited[current.second][current.first + 1] = visited[current.second][current.first] + 1;
				}
			}

			if (visited[m][n] != -1) {
				return;
			}
		}
	}();
}

int main()
{
	for (int i = 0; i < 105; ++i) {
		for (int j = 0; j < 105; ++j) {
			map[i][j] = false;
		}
	}
	for (int i = 0; i < 105; ++i) {
		for (int j = 0; j < 105; ++j) {
			visited[i][j] = -1;
		}
	}
	cin >> n >> m;
	char inputdata;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> inputdata;
			map[i][j] = inputdata - '0';
		}
	}
	bfs(1, 1);
	//for (int i = 1; i <= n; ++i) {
	//	for (int j = 1; j <= m; ++j) {
	//		cout << visited[i][j];
	//	}
	//	cout << endl;
	//}
	cout << visited[n][m] << endl;
}