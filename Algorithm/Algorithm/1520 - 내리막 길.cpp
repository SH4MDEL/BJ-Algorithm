#include <iostream>
#define inf 987654321 
#define endl "\n"
using namespace std;

int table[502][502];
int cache[502][502];
int m, n;

int Search(int x, int y, int depth)
{
	if (x == n && y == m) {
		return cache[y][x] = 1;
	}
	if (cache[y][x] != -1) {
		return cache[y][x];
	}

	cache[y][x] = 0;
	if (table[y - 1][x] < table[y][x]) {
		cache[y][x] += Search(x, y - 1, table[y][x]);
	}
	if (table[y + 1][x] < table[y][x]) {
		cache[y][x] += Search(x, y + 1, table[y][x]);
	}
	if (table[y][x - 1] < table[y][x]) {
		cache[y][x] += Search(x - 1, y, table[y][x]);
	}
	if (table[y][x + 1] < table[y][x]) {
		cache[y][x] += Search(x + 1, y, table[y][x]);
	}
	return cache[y][x];
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	for (int i = 0; i < 502; ++i) {
		for (int j = 0; j < 502; ++j) {
			table[i][j] = inf;
		}
	}
	for (int i = 0; i < 502; ++i) {
		for (int j = 0; j < 502; ++j) {
			cache[i][j] = -1;
		}
	}

	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> table[i][j];
		}
	}

	cout << Search(1, 1, inf) << endl;
	//for (int i = 1; i <= m; ++i) {
	//	for (int j = 1; j <= n; ++j) {
	//		cout << cache[i][j] << " ";
	//	}
	//	cout << endl;
	//}
}