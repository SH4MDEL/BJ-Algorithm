#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define mod 1000000
#define ll long long
#define endl "\n"
using namespace std;

string s;
ll cache[5500];

ll dp(int depth)
{
	if (depth == s.length()) return 1;
	if (s[depth] == '0') return 0;
	if (cache[depth] != -1) return cache[depth];

	if ((s[depth] == '1' && depth + 1 != s.length()) ||
		(s[depth] == '2' && depth + 1 != s.length() && s[depth + 1] <= '6')) {
		if (s[depth + 1] == '0') return cache[depth] = dp(depth + 2) % mod;
		return cache[depth] = (dp(depth + 1) % mod + dp(depth + 2) % mod) % mod;
	}
	return cache[depth] = dp(depth + 1) % mod;
}

int main()
{
	fastip; sws;
	memset(cache, -1, sizeof cache);

	cin >> s;
	cout << dp(0);
}