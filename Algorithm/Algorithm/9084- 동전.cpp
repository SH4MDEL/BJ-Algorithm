#include <iostream>
#include <algorithm>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int t, n, m;
int coin[22];
int cache[10101][22];

int dp(int target, int depth)
{
	if (target == 0) return 1;
	if (depth == n) return 0;
	if (cache[target][depth] != -1) return cache[target][depth];

	int num = 0, ans = 0;
	while (target >= coin[depth] * num) {
		ans += dp(target - coin[depth] * num, depth + 1);
		++num;
	}
	return cache[target][depth] = ans;
}

int main()
{
	fastip; sws;

	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof cache);
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> coin[i];
		}
		cin >> m;
		cout << dp(m, 0) << endl;
	}
}