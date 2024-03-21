#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

int t, h, w;
int key;

char building[105][105];
bool visited[105][105];
queue<pair<int, int>> q;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool searchkey()
{
	while (!q.empty()) {
		auto now = q.front(); q.pop();
		int ny = now.first; int nx = now.second;

		for (int i = 0; i < 4; ++i) {
			int ty = ny + dy[i];
			int tx = nx + dx[i];
			if ((building[ty][tx] == '.' || building[ty][tx] == '$' || 
				(building[ty][tx] >= 'a' && building[ty][tx] <= 'z')) &&
				!visited[ty][tx] && ty != 0 && ty != h + 1 && tx != 0 && tx != w + 1) {
				if ((building[ty][tx] >= 'a' && building[ty][tx] <= 'z')) {
					key |= (1 << (building[ty][tx] - 'a'));
					return true;
				}
				visited[ty][tx] = true;
				q.push({ty, tx});
			}
		}
	}
	return false;
}

int bfs()
{
	memset(visited, false, sizeof visited);
	int ans = 0;
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			if ((i == 1 || i == h || j == 1 || j == w) &&
				(building[i][j] == '.' || building[i][j] == '$')) {
				if (building[i][j] == '$') {
					building[i][j] = '.';
					++ans;
				}
				visited[i][j] = true;
				q.push({ i, j });
			}
		}
	}
	while (!q.empty()) {
		auto now = q.front(); q.pop();
		int ny = now.first; int nx = now.second;

		for (int i = 0; i < 4; ++i) {
			int ty = ny + dy[i];
			int tx = nx + dx[i];
			if ((building[ty][tx] == '.' || building[ty][tx] == '$') && 
				!visited[ty][tx] && ty != 0 && ty != h + 1 && tx != 0 && tx != w + 1) {
				if (building[ty][tx] == '$') {
					++ans;
					building[ty][tx] = '.';
				}
				visited[ty][tx] = true;
				q.push({ ty, tx });
			}
		}
	}
	return ans;
}

int main()
{
	fastip; sws;
	cin >> t;
	while (t--) {
		key = 0;
		cin >> h >> w;
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				char c;
				cin >> c;
				building[i][j] = c;
			}
		}
		string s;
		cin >> s;
		if (s != "0") {
			for (const auto& e : s) {
				key |= (1 << (e - 'a'));
			}
		}
		do {
			memset(visited, false, sizeof visited);
			while (!q.empty()) q.pop();

			for (int i = 1; i <= h; ++i) {
				for (int j = 1; j <= w; ++j) {
					if (building[i][j] >= 'A' && building[i][j] <= 'Z' &&
						(key & (1 << (building[i][j] - 'A')))) {
						building[i][j] = '.';
					}
					if (building[i][j] >= 'a' && building[i][j] <= 'z' &&
						(key & (1 << (building[i][j] - 'a')))) {
						building[i][j] = '.';
					}
					if ((i == 1 || i == h || j == 1 || j == w) &&
						(building[i][j] == '.' || building[i][j] == '$' || 
							(building[i][j] >= 'a' && building[i][j] <= 'z'))) {
						if ((building[i][j] >= 'a' && building[i][j] <= 'z')) {
							key |= (1 << (building[i][j] - 'a'));
							building[i][j] = '.';
						}
						visited[i][j] = true;
						q.push({ i, j });
					}
				}
			}
		} while (searchkey());

		while (!q.empty()) q.pop();

		cout << bfs() << endl;
	}
}