#include <iostream>
#include <string>
#include <memory.h>
#include <queue>
#include <stack>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

int n, l, r, ans;
int field[55][55];
bool border[2][55][55];

bool open()
{
	bool moved = false;
	memset(border, false, sizeof border);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < n; ++j) {
			int def = abs(field[i][j] - field[i][j + 1]);
			if (def >= l && def <= r) {
				border[0][i][j] = true;
				moved = true; 
			}
		}
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int def = abs(field[i][j] - field[i + 1][j]);
			if (def >= l && def <= r) {
				border[1][i][j] = true;
				moved = true;
			}
		}
	}

	if (!moved) return false;
	++ans; 
	return true;
}

bool visited[55][55];

void bfs(pair<int, int> start)
{
	queue<pair<int, int>> q;
	stack<pair<int, int>> s;
	visited[start.first][start.second] = true;
	q.push(start);
	s.push(start);
	int sum = field[start.first][start.second];

	while (!q.empty()) {
		auto now = q.front(); q.pop();
		{ auto ny = now.first; auto nx = now.second + 1;
		if (ny != n + 1 && ny != 0 && nx != n + 1 && nx != 0 &&
			!visited[ny][nx] && border[0][now.first][now.second]) {
			visited[ny][nx] = true;
			q.push({ny, nx});
			s.push({ ny, nx });
			sum += field[ny][nx];
		} }
		{ auto ny = now.first; auto nx = now.second - 1;
		if (ny != n + 1 && ny != 0 && nx != n + 1 && nx != 0 &&
			!visited[ny][nx] && border[0][now.first][now.second - 1]) {
			visited[ny][nx] = true;
			q.push({ ny, nx });
			s.push({ ny, nx });
			sum += field[ny][nx];
		} }
		{ auto ny = now.first + 1; auto nx = now.second;
		if (ny != n + 1 && ny != 0 && nx != n + 1 && nx != 0 &&
			!visited[ny][nx] && border[1][now.first][now.second]) {
			visited[ny][nx] = true;
			q.push({ ny, nx });
			s.push({ ny, nx });
			sum += field[ny][nx];
		} }
		{ auto ny = now.first - 1; auto nx = now.second;
		if (ny != n + 1 && ny != 0 && nx != n + 1 && nx != 0 &&
			!visited[ny][nx] && border[1][now.first - 1][now.second]) {
			visited[ny][nx] = true;
			q.push({ ny, nx });
			s.push({ ny, nx });
			sum += field[ny][nx];
		} }
	}

	auto size = s.size();
	while (!s.empty()) {
		auto now = s.top(); s.pop();
		field[now.first][now.second] = sum / size;
	}
}

void moving()
{
	memset(visited, false, sizeof visited);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (!visited[i][j]) {
				bfs({ i, j });
			}
		}
	}
}

int main()
{
	fastip; sws;
	cin >> n >> l >> r;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> field[i][j];
		}
	}
	while (open()) {
		moving();
	}
	cout << ans;
}