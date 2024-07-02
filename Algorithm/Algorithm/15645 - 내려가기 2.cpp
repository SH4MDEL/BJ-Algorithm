#include <iostream>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define endl "\n"
using namespace std;

int n;
int field[100100][3];
int cache[100100][3];
int ans[2];

int main()
{
	fastip; sws;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> field[i][0] >> field[i][1] >> field[i][2];
	}
	for (int i = 1; i <= n; ++i) {
		cache[i][0] = max(cache[i - 1][0], cache[i - 1][1]) + field[i][0];
		cache[i][1] = max({ cache[i - 1][0], cache[i - 1][1], cache[i - 1][2]}) + field[i][1];
		cache[i][2] = max(cache[i - 1][1], cache[i - 1][2]) + field[i][2];
	}
	ans[0] = max({cache[n][0], cache[n][1], cache[n][2]});
	memset(cache, 0, sizeof cache);
	for (int i = 1; i <= n; ++i) {
		cache[i][0] = min(cache[i - 1][0], cache[i - 1][1]) + field[i][0];
		cache[i][1] = min({ cache[i - 1][0], cache[i - 1][1], cache[i - 1][2] }) + field[i][1];
		cache[i][2] = min(cache[i - 1][1], cache[i - 1][2]) + field[i][2];
	}
	ans[1] = min({ cache[n][0], cache[n][1], cache[n][2] });

	cout << ans[0] << " " << ans[1];
}