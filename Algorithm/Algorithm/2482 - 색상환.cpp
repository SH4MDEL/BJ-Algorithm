#include <iostream>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define mod 1'000'000'003
#define endl "\n"
#define ll long long
using namespace std;

// n개 중 k를 선택하는 경우의 수
ll cache[1010][1010][2];

ll dp(int now, int least, int selected)
{
	if (now < 0 || least < 0) return -inf;
	if (now == 2) {
		if (least == 0 && !selected) return 1LL;
		if (least == 1) return 1LL;
		return -inf;
	}
	if (now == 1) {
		if (!selected && least == 0) return 1LL;
		if (selected && least == 1) return 1LL;
		return -inf;
	}

	if (cache[now][least][selected] != -1)
		return cache[now][least][selected] % mod;

	ll ans = 0, result = 0;
	result = dp(now - 2, least - 1, selected);
	if (result != -inf) ans += result;
	result = dp(now - 1, least, selected);
	if (result != -inf) ans += result;
	return cache[now][least][selected] = ans % mod;
}

int main()
{
	fastip; sws;
	memset(cache, -1, sizeof cache);

	int n, k;
	cin >> n >> k;
	ll ans = 0, result = 0;
	result = dp(n, k, false);
	if (result != -inf) ans += result;
	result = dp(n - 1, k, true);
	if (result != -inf) ans += result;
	cout << ans % mod;
}