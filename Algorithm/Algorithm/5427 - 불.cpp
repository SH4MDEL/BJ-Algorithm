#include <iostream>
#include <queue>
#define endl "\n"
#define inf 987654321
using namespace std;

int n, w, h;

char map[1002][1002];
int visited[1002][1002];

queue<pair<int, int>> fireq;
queue<pair<int, int>> q;

int answer = -1;

void bfs()
{
	[&]() {
		while (!q.empty()) {
			auto fireqsize = fireq.size();
			for (int i = 0; i < fireqsize; ++i) {
				pair<int, int> current = fireq.front();
				fireq.pop();
				if (map[current.second + 1][current.first] == '.') {
					map[current.second + 1][current.first] = '*';
					fireq.push(make_pair(current.first, current.second + 1));
				}
				if (map[current.second - 1][current.first] == '.') {
					map[current.second - 1][current.first] = '*';
					fireq.push(make_pair(current.first, current.second - 1));
				}
				if (map[current.second][current.first + 1] == '.') {
					map[current.second][current.first + 1] = '*';
					fireq.push(make_pair(current.first + 1, current.second));
				}
				if (map[current.second][current.first - 1] == '.') {
					map[current.second][current.first - 1] = '*';
					fireq.push(make_pair(current.first - 1, current.second));
				}
			}

			auto qsize = q.size();
			for (int i = 0; i < qsize; ++i) {
				pair<int, int> current = q.front();
				q.pop();

				if (current.first == 1 || current.first == w || current.second == 1 || current.second == h) {
					answer = visited[current.second][current.first];
					return;
				}

				if (visited[current.second + 1][current.first] == -1 && map[current.second + 1][current.first] == '.') {
					visited[current.second + 1][current.first] = visited[current.second][current.first] + 1;
					q.push(make_pair(current.first, current.second + 1));
				}
				if (visited[current.second - 1][current.first] == -1 && map[current.second - 1][current.first] == '.') {
					visited[current.second - 1][current.first] = visited[current.second][current.first] + 1;
					q.push(make_pair(current.first, current.second - 1));
				}
				if (visited[current.second][current.first + 1] == -1 && map[current.second][current.first + 1] == '.') {
					visited[current.second][current.first + 1] = visited[current.second][current.first] + 1;
					q.push(make_pair(current.first + 1, current.second));
				}
				if (visited[current.second][current.first - 1] == -1 && map[current.second][current.first - 1] == '.') {
					visited[current.second][current.first - 1] = visited[current.second][current.first] + 1;
					q.push(make_pair(current.first - 1, current.second));
				}
			}
		}
	} ();
}

int main()
{
	cin >> n;
	for (int a = 0; a < n; ++a) {
		answer = -1;
		while (!fireq.empty()) {
			fireq.pop();
		}
		while (!q.empty()) {
			q.pop();
		}
		for (int i = 0; i < 1002; ++i) {
			for (int j = 0; j < 1002; ++j) {
				map[i][j] = 'a';
			}
		}
		for (int i = 0; i < 1002; ++i) {
			for (int j = 0; j < 1002; ++j) {
				visited[i][j] = -1;
			}
		}
		cin >> w >> h;
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				cin >> map[i][j];
				if (map[i][j] == '@') {
					q.push(make_pair(j, i));
					visited[i][j] = 1;
				}
				if (map[i][j] == '*') {
					fireq.push(make_pair(j, i));
				}
			}
		}
		bfs();
		if (answer == -1) {
			cout << "IMPOSSIBLE" << endl;
		}
		else{
			cout << answer << endl;
		}
	}
}