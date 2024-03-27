#include <iostream>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

int m, n;
int field[505][505];
int cache[505][505];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int dp(int y, int x)
{
	if (y == m && x == n) return cache[y][x] = 1;
	if (cache[y][x] != -1) return cache[y][x];

	int ans = 0;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny != 0 && ny != m + 1 &&
			nx != 0 && nx != n + 1 &&
			field[ny][nx] < field[y][x]) {
			ans += dp(ny, nx);
		}
	}
	return cache[y][x] = ans;
}

int main()
{
	fastip; sws;

	memset(cache, -1, sizeof cache);

	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> field[i][j];
		}
	}
	cout << dp(1, 1);

}