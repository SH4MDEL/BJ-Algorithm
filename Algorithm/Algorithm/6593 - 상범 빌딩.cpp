#include <iostream>
#include <queue>
#define endl "\n"
#define inf 987654321
using namespace std;

char map[32][32][32];
int visited[32][32][32];
int a, b, c;

int ei = 0, ej = 0, ek = 0;
int si = 0, sj = 0, sk = 0;

struct FLOAT3 {
	int x, y, z;
	FLOAT3(int x, int y, int z) : x(x), y(y), z(z) {}
	//FLOAT3(FLOAT3& f3) : x(f3.x), y(f3.y), z(f3.z) {}
};

queue<FLOAT3> q;

void bfs(int x, int y, int z)
{
	FLOAT3 f3(x, y, z);
	visited[z][y][x] = 0;
	q.push(f3);

	[&]() {
		while (!q.empty()) {
			auto qsize = q.size();
			for (int i = 0; i < qsize; ++i) {
				FLOAT3 f3 = q.front();
				q.pop();

				if (visited[ei][ej][ek] != -1) {
					return;
				}

				if (visited[f3.z + 1][f3.y][f3.x] == -1 && map[f3.z + 1][f3.y][f3.x] != '#') {
					visited[f3.z + 1][f3.y][f3.x] = visited[f3.z][f3.y][f3.x] + 1;
					q.push(FLOAT3(f3.x, f3.y, f3.z + 1));
				}
				if (visited[f3.z - 1][f3.y][f3.x] == -1 && map[f3.z - 1][f3.y][f3.x] != '#') {
					visited[f3.z - 1][f3.y][f3.x] = visited[f3.z][f3.y][f3.x] + 1;
					q.push(FLOAT3(f3.x, f3.y, f3.z - 1));
				}
				if (visited[f3.z][f3.y + 1][f3.x] == -1 && map[f3.z][f3.y + 1][f3.x] != '#') {
					visited[f3.z][f3.y + 1][f3.x] = visited[f3.z][f3.y][f3.x] + 1;
					q.push(FLOAT3(f3.x, f3.y + 1, f3.z));
				}
				if (visited[f3.z][f3.y - 1][f3.x] == -1 && map[f3.z][f3.y - 1][f3.x] != '#') {
					visited[f3.z][f3.y - 1][f3.x] = visited[f3.z][f3.y][f3.x] + 1;
					q.push(FLOAT3(f3.x, f3.y - 1, f3.z));
				}
				if (visited[f3.z][f3.y][f3.x + 1] == -1 && map[f3.z][f3.y][f3.x + 1] != '#') {
					visited[f3.z][f3.y][f3.x + 1] = visited[f3.z][f3.y][f3.x] + 1;
					q.push(FLOAT3(f3.x + 1, f3.y, f3.z));
				}
				if (visited[f3.z][f3.y][f3.x - 1] == -1 && map[f3.z][f3.y][f3.x - 1] != '#') {
					visited[f3.z][f3.y][f3.x - 1] = visited[f3.z][f3.y][f3.x] + 1;
					q.push(FLOAT3(f3.x - 1, f3.y, f3.z));
				}
			}
		}
	}();
}

int main()
{
	while (1) {
		while (!q.empty()) {
			q.pop();
		}
		ei = -1;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		for (int i = 0; i < 32; ++i) {
			for (int j = 0; j < 32; ++j) {
				for (int k = 0; k < 32; ++k) {
					map[i][j][k] = '#';
				}
			}
		}
		for (int i = 0; i < 32; ++i) {
			for (int j = 0; j < 32; ++j) {
				for (int k = 0; k < 32; ++k) {
					visited[i][j][k] = -1;
				}
			}
		}
		for (int i = 1; i <= a; ++i) {
			for (int j = 1; j <= b; ++j) {
				for (int k = 1; k <= c; ++k) {
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S') {
						si = i; sj = j; sk = k;
					}
					if (map[i][j][k] == 'E') {
						ei = i; ej = j; ek = k;
					}
				}
			}
		}
		bfs(sk, sj, si);
		if (visited[ei][ej][ek] == -1) {
			cout << "Trapped!" << endl;
		}
		else {
			cout << "Escaped in " << visited[ei][ej][ek] << " minute(s)." << endl;
		}
	}
}