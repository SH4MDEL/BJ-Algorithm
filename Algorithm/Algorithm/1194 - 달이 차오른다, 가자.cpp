#include <iostream>
#include <map>
#define endl "\n"
#define inf 987654321
using namespace std;

char cmap[52][52];
int n, m;

map<pair<int, int>, int> visited_map;

int depthcount = inf;

void Search(int x, int y, int key, int depth)
{
	if (cmap[y][x] >= 'a' && cmap[y][x] <= 'f') {
		key |= (1 << (int)(cmap[y][x] - 'a'));

	}

	if ((visited_map.find(make_pair(y * (n + 1) + x, key))) != visited_map.end()) {
		if (visited_map[make_pair(y * (n + 1) + x, key)] < depth) {
			return;
		}
	}
	visited_map[make_pair(y * (n + 1) + x, key)] = depth;

	if (depth > depthcount) {
		return;
	}
	if (cmap[y][x] >= 'A' && cmap[y][x] <= 'F') {
		if (key & (1 << (int)(cmap[y][x] - 'A'))) {
		}
		else {
			return;
		}
	}
	if (cmap[y][x] == '#') {
		return;
	}

	if (cmap[y][x] == '1') {
		if (depthcount > depth) {
			depthcount = depth;
		}
		return;
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
			cmap[i][j] = '#';
		}
	}
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> cmap[i][j];
			if (cmap[i][j] == '0') {
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