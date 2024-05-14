#include <iostream>
#include <algorithm>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int n;
int num[110];
ll cache[110][22];

ll dp(int now, int depth)
{
	if (depth == n - 1) {
		if (now == num[n - 1]) return 1;
		return 0;
	}
	if (cache[depth][now] != -1) return cache[depth][now];

	ll result = 0;
	if (now - num[depth] >= 0) result += dp(now - num[depth], depth + 1);
	if (now + num[depth] <= 20) result += dp(now + num[depth], depth + 1);
	return cache[depth][now] = result;
}

int main()
{
	fastip; sws;
	memset(cache, -1, sizeof cache);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	cout << dp(num[0], 1);
}