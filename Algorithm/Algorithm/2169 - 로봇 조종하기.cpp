#include <iostream>
#include <string>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

int cache[1010][1010][3];
int field[1010][1010];
int n, m;

// direction 0일 시 좌우 이동 가능, 
// 1일 시 우로만 이동 가능, 
// 2일 시 좌로만 이동 가능
int dp(int direction, int y, int x)
{
	if (y == n && x == m) return field[y][x];

	if (cache[y][x][direction] != -1) return cache[y][x][direction];

	if (y == n) {
		if (direction == 2) return cache[y][x][direction] = -inf;
		return cache[y][x][direction] = dp(1, y, x + 1) + field[y][x];
	}
	int ans = -inf;
	if (direction == 0) {
		ans = max(ans, dp(0, y + 1, x) + field[y][x]);
		if (x != m) ans = max(ans, dp(1, y, x + 1) + field[y][x]);
		if (x != 1) ans = max(ans, dp(2, y, x - 1) + field[y][x]);
	}
	if (direction == 1) {
		ans = max(ans, dp(0, y + 1, x) + field[y][x]);
		if (x != m) ans = max(ans, dp(1, y, x + 1) + field[y][x]);
	}
	if (direction == 2) {
		ans = max(ans, dp(0, y + 1, x) + field[y][x]);
		if (x != 1) ans = max(ans, dp(2, y, x - 1) + field[y][x]);
	}
	return cache[y][x][direction] = ans;
}

int main()
{
	fastip; sws;
	memset(cache, -1, sizeof cache);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> field[i][j];
		}
	}
	cout << dp(0, 1, 1);
}