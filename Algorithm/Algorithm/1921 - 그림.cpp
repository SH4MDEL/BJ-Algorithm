#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <unordered_set>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;
int map[510][510];
bool searched[510][510];

int Search(int y, int x)
{
	if (y > n || y < 1 || x > m || x < 1) return 0;
	if (map[y][x] == 0 || searched[y][x]) return 0;
	searched[y][x] = true;

	return 1 + Search(y + 1, x) + Search(y - 1, x) + Search(y, x + 1) + Search(y, x - 1);
}

int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> map[i][j];
		}
	}

	int ans = 0;
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int area = Search(i, j);
			if (area) {
				++ans;
				sum = max(sum, area);
			}
		}
	}
	cout << ans << endl << sum;
}