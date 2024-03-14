#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define mod 1'000'000'007
#define ll long long
#define endl "\n"
using namespace std;

int n;
ll cache[5][200200];

int main()
{
	fastip; sws;

	cin >> n;
	cache[0][0] = cache[1][0] = cache[2][0] = cache[3][0] = cache[4][0] = 1LL;

	for (int i = 1; i < n; ++i) {
		cache[0][i] = (cache[1][i - 1] % mod + cache[2][i - 1] % mod + cache[3][i - 1] % mod + cache[4][i - 1] % mod) % mod;
		cache[1][i] = cache[4][i] = (cache[0][i - 1] % mod + cache[1][i - 1] % mod + cache[2][i - 1] % mod) % mod;
		cache[2][i] = cache[3][i] = (cache[0][i - 1] % mod + cache[1][i - 1] % mod) % mod;
	}

	ll ans = 0;
	for (int i = 0; i < 5; ++i) {
		ans += cache[i][n - 1];
	}
	cout << ans % mod << endl;
}