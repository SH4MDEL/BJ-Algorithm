#include <iostream>
#include <queue>
#define endl "\n"
#define inf 987654321
using namespace std;

char cmap[52][52];
int n, m;
int counter;

int visited[52][52][1 << 6];	// y, x, key
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int y, int x)
{
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, {y, x} });
	visited[y][x][0] = 1;

	while (!q.empty()) {

		int key = q.front().first;
		int nowy = q.front().second.first;
		int nowx = q.front().second.second;
		int oldkey = key;
		q.pop();

		if (cmap[nowy][nowx] == '1') {
			if (visited[nowy][nowx][key] < counter) {
				counter = visited[nowy][nowx][key];
			}
			continue;
		}
		if (visited[nowy][nowx][key] >= counter) continue;
		if (cmap[nowy][nowx] == '#') continue;
		if (cmap[nowy][nowx] >= 'a' && cmap[nowy][nowx] <= 'f') {
			key |= (1 << (int)(cmap[nowy][nowx] - 'a'));
		}
		if (cmap[nowy][nowx] >= 'A' && cmap[nowy][nowx] <= 'F') {
			if (!(key & (1 << (int)(cmap[nowy][nowx] - 'A')))) continue;
		}

		for (int i = 0; i < 4; ++i) {
			int ty = nowy + dy[i];
			int tx = nowx + dx[i];
			if (ty < 1 || ty > n || tx < 1 || tx > m) continue;

			if (visited[ty][tx][key] == 0) {
				q.push({ key, {ty, tx} });
				visited[ty][tx][key] = visited[nowy][nowx][oldkey] + 1;
			}
		}
	}
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n >> m;
	
	counter = inf;
	int startx, starty;
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= m + 1; ++j) {
			cmap[i][j] = '#';
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> cmap[i][j];
			if (cmap[i][j] == '0') {
				starty = i; startx = j;
			}
		}
	}
	bfs(starty, startx);
	if (counter == inf) cout << "-1" << endl;
	else cout << counter - 1 << endl;
}