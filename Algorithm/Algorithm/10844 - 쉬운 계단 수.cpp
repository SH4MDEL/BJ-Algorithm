#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'000;
using namespace std;

int n;
int cache[101][10];

int dp(int n, int now)
{
	if (cache[n][now] != 0) return cache[n][now];
	if (n == 1) return cache[1][now] = 1;

	if (now == 9) {
		return cache[n][now] = dp(n - 1, now - 1) % mod;
	}
	if (now == 0) {
		return cache[n][now] = dp(n - 1, now + 1) % mod;
	}
	return cache[n][now] = (dp(n - 1, now - 1) + dp(n - 1, now + 1)) % mod;
}

int main()
{
	fastip; sws;

	cin >> n;
	int ans = 0;
	for (int i = 1; i <= 9; ++i) {
		ans += dp(n, i);
		ans %= mod;
	}
	cout << ans << endl;
}