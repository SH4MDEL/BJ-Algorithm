#include <iostream>
#define endl "\n"
#define inf 987654321
using namespace std;

char map[52][52];
bool visited[52][52][((1 << 6) + 1)];
int n, m;

int depthcount = inf;

bool Search(int x, int y, int key, int depth)
{
	if (depth > depthcount) {
		return false;
	}
	if (visited[y][x][key]) {
		return false;
	}
	visited[y][x][key] = true;
	if (map[y][x] == '#') {
		return false;
	}
	if (map[y][x] >= 'a' && map[y][x] <= 'f') {
		key |= (1 << (int)(map[y][x] - 'a' + 1));
	}
	if (map[y][x] >= 'A' && map[y][x] <= 'F') {
		if (key & (1 << (int)(map[y][x] - 'A' + 1))) {
		}
		else {
			return false;
		}
	}
	if (map[y][x] == '1') {
		if (depthcount > depth) {
			depthcount = depth;
		}
		return true;
	}
	Search(x - 1, y, key, depth + 1);
	Search(x + 1, y, key, depth + 1);
	Search(x, y - 1, key, depth + 1);
	Search(x, y + 1, key, depth + 1);
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	int startx = 0, starty = 0;

	for (int i = 0; i < 52; ++i) {
		for (int j = 0; j < 52; ++j) {
			map[i][j] = '#';
			for (int k = 0; k < ((1 << 6) + 1); ++k) {
				visited[i][j][k] = false;
			}
		}
	}
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				starty = i, startx = j;
			}
		}
	}
	Search(startx, starty, 0, 0);
	if (depthcount == inf) {
		cout << "-1" << endl;
	}
	else {
		cout << depthcount << endl;
	}
}