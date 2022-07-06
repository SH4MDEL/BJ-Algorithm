#include <iostream>
#include <queue>
#define endl "\n"
#define inf 987654321
using namespace std;

char map[52][52];
int visited[52][52];

queue<pair<int, int>> waterq;
queue<pair<int, int>> q;

int r, c, ex, ey;

void bfs()
{
	[&]() {
		while (!q.empty()) {
			auto waterqsize = waterq.size();
			for (int i = 0; i < waterqsize; ++i) {
				pair<int, int> current = waterq.front();
				waterq.pop();

				if (map[current.second + 1][current.first] == '.') {
					map[current.second + 1][current.first] = '*';
					waterq.push(make_pair(current.first, current.second + 1));
				}
				if (map[current.second - 1][current.first] == '.') {
					map[current.second - 1][current.first] = '*';
					waterq.push(make_pair(current.first, current.second - 1));
				}
				if (map[current.second][current.first + 1] == '.') {
					map[current.second][current.first + 1] = '*';
					waterq.push(make_pair(current.first + 1, current.second));
				}
				if (map[current.second][current.first - 1] == '.') {
					map[current.second][current.first - 1] = '*';
					waterq.push(make_pair(current.first - 1, current.second));
				}
			}

			auto qsize = q.size();
			for (int i = 0; i < qsize; ++i) {
				pair<int, int> current = q.front();
				q.pop();

				if (map[current.second][current.first] == 'D') {
					return;
				}

				if (visited[current.second + 1][current.first] == -1 && (map[current.second + 1][current.first] == '.' || map[current.second + 1][current.first] == 'D')) {
					visited[current.second + 1][current.first] = visited[current.second][current.first] + 1;
					q.push(make_pair(current.first, current.second + 1));
				}
				if (visited[current.second - 1][current.first] == -1 && map[current.second - 1][current.first] == '.' || map[current.second - 1][current.first] == 'D') {
					visited[current.second - 1][current.first] = visited[current.second][current.first] + 1;
					q.push(make_pair(current.first, current.second - 1));
				}
				if (visited[current.second][current.first + 1] == -1 && map[current.second][current.first + 1] == '.' || map[current.second][current.first + 1] == 'D') {
					visited[current.second][current.first + 1] = visited[current.second][current.first] + 1;
					q.push(make_pair(current.first + 1, current.second));
				}
				if (visited[current.second][current.first - 1] == -1 && map[current.second][current.first - 1] == '.' || map[current.second][current.first - 1] == 'D') {
					visited[current.second][current.first - 1] = visited[current.second][current.first] + 1;
					q.push(make_pair(current.first - 1, current.second));
				}
			}
		}
	}();
}

int main()
{
	for (int i = 0; i < 52; ++i) {
		for (int j = 0; j < 52; ++j) {
			map[i][j] = 'X';
		}
	}
	for (int i = 0; i < 52; ++i) {
		for (int j = 0; j < 52; ++j) {
			visited[i][j] = -1;
		}
	}
	cin >> r >> c;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				visited[i][j] = 0;
				map[i][j] = '.';
				q.push(make_pair(j, i));
			}
			if (map[i][j] == '*') {
				waterq.push(make_pair(j, i));
			}
			if (map[i][j] == 'D') {
				ex = j; ey = i;
			}
		}
	}
	bfs();
	//for (int i = 1; i <= r; ++i) {
	//	for (int j = 1; j <= c; ++j) {
	//		cout << map[i][j];
	//	}
	//	cout << endl;
	//}
	//for (int i = 1; i <= r; ++i) {
	//	for (int j = 1; j <= c; ++j) {
	//		cout << visited[i][j];
	//	}
	//	cout << endl;
	//}
	if (visited[ey][ex] == -1) {
		cout << "KAKTUS" << endl;
	}
	else {
		cout << visited[ey][ex] << endl;
	}
}