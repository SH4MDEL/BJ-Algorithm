#include <iostream>
#include <queue>
#define endl "\n"
#define inf 987654321
using namespace std;

char map[2][1005][1005];
int visited[2][1005][1005];
int n, m;

struct FLOAT3 {
	int x, y, z;
	FLOAT3(int x, int y, int z) : x(x), y(y), z(z) {}
	//FLOAT3(FLOAT3& f3) : x(f3.x), y(f3.y), z(f3.z) {}
};

queue<FLOAT3> q;

void bfs()
{
	while (!q.empty()) {
		auto qsize = q.size();
		for (int i = 0; i < qsize; ++i) {
			FLOAT3 current = q.front();
			q.pop();

			if (visited[0][n][m] != -1 || visited[1][n][m] != -1) {
				return;
			}

			if (current.z == 0) {
				if (visited[0][current.y - 1][current.x] == -1 && map[0][current.y - 1][current.x] == '0') {
					visited[0][current.y - 1][current.x] = visited[0][current.y][current.x] + 1;
					q.push(FLOAT3(current.x, current.y - 1, 0));
				}
				if (visited[0][current.y + 1][current.x] == -1 && map[0][current.y + 1][current.x] == '0') {
					visited[0][current.y + 1][current.x] = visited[0][current.y][current.x] + 1;
					q.push(FLOAT3(current.x, current.y + 1, 0));
				}
				if (visited[0][current.y][current.x - 1] == -1 && map[0][current.y][current.x - 1] == '0') {
					visited[0][current.y][current.x - 1] = visited[0][current.y][current.x] + 1;
					q.push(FLOAT3(current.x - 1, current.y, 0));
				}
				if (visited[0][current.y][current.x + 1] == -1 && map[0][current.y][current.x + 1] == '0') {
					visited[0][current.y][current.x + 1] = visited[0][current.y][current.x] + 1;
					q.push(FLOAT3(current.x + 1, current.y, 0));
				}

				if (visited[1][current.y - 1][current.x] == -1 && map[1][current.y - 1][current.x] == '1') {
					visited[1][current.y - 1][current.x] = visited[0][current.y][current.x] + 1;
					q.push(FLOAT3(current.x, current.y - 1, 1));
				}
				if (visited[1][current.y + 1][current.x] == -1 && map[1][current.y + 1][current.x] == '1') {
					visited[1][current.y + 1][current.x] = visited[0][current.y][current.x] + 1;
					q.push(FLOAT3(current.x, current.y + 1, 1));
				}
				if (visited[1][current.y][current.x - 1] == -1 && map[1][current.y][current.x - 1] == '1') {
					visited[1][current.y][current.x - 1] = visited[0][current.y][current.x] + 1;
					q.push(FLOAT3(current.x - 1, current.y, 1));
				}
				if (visited[1][current.y][current.x + 1] == -1 && map[1][current.y][current.x + 1] == '1') {
					visited[1][current.y][current.x + 1] = visited[0][current.y][current.x] + 1;
					q.push(FLOAT3(current.x + 1, current.y, 1));
				}
			}
			if (current.z == 1) {
				if (visited[1][current.y - 1][current.x] == -1 && map[1][current.y - 1][current.x] == '0') {
					visited[1][current.y - 1][current.x] = visited[1][current.y][current.x] + 1;
					q.push(FLOAT3(current.x, current.y - 1, 1));
				}
				if (visited[1][current.y + 1][current.x] == -1 && map[1][current.y + 1][current.x] == '0') {
					visited[1][current.y + 1][current.x] = visited[1][current.y][current.x] + 1;
					q.push(FLOAT3(current.x, current.y + 1, 1));
				}
				if (visited[1][current.y][current.x - 1] == -1 && map[1][current.y][current.x - 1] == '0') {
					visited[1][current.y][current.x - 1] = visited[1][current.y][current.x] + 1;
					q.push(FLOAT3(current.x - 1, current.y, 1));
				}
				if (visited[1][current.y][current.x + 1] == -1 && map[1][current.y][current.x + 1] == '0') {
					visited[1][current.y][current.x + 1] = visited[1][current.y][current.x] + 1;
					q.push(FLOAT3(current.x + 1, current.y, 1));
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 1005; ++j) {
			for (int k = 0; k < 1005; ++k) {
				map[i][j][k] = 'D';
			}
		}
	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 1005; ++j) {
			for (int k = 0; k < 1005; ++k) {
				visited[i][j][k] = -1;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> map[0][i][j];
			map[1][i][j] = map[0][i][j];
		}
	}
	visited[0][1][1] = 1;
	q.push(FLOAT3(1, 1, 0));
	bfs();
	if (visited[0][n][m] != -1 && visited[1][n][m] != -1) {
		cout << "-1" << endl;
	}
	else {
		if (visited[0][n][m] != -1) {
			cout << visited[0][n][m] << endl;
		}
		else {
			cout << visited[1][n][m] << endl;
		}
	}
}