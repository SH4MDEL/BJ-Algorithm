#include <iostream>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

int n;
ll cache[110][10][3][3];

ll dp(int depth, int start, int up, int down)
{
	if (depth == n) return 1;
	if (cache[depth][start][up][down] != -1) return cache[depth][start][up][down];

	ll ans = 0;
	if (start != 0 && down != 2) {
		ans += dp(depth + 1, start - 1, 0, down + 1) % mod;
	}
	if (start != 9 && up != 2) {
		ans += dp(depth + 1, start + 1, up + 1, 0) % mod;
	}
	return cache[depth][start][up][down] = ans % mod;
}

int main()
{
	fastip; sws;

	memset(cache, -1, sizeof cache);

	cin >> n;

	ll ans = 0;
	for (int i = 0; i < 10; ++i) {
		ans += dp(1, i, 0, 0) % mod;
	}
	cout << ans % mod;

}