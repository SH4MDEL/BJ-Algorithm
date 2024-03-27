#include <iostream>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 1987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

int cache[1500150];
int tp[1500150][2];
int n;

int dp(int depth)
{
	if (depth == n) return 0;
	if (depth > n) return -inf;
	if (cache[depth] != -1) return cache[depth];

	return cache[depth] = max(dp(depth + 1), dp(depth + tp[depth][0]) + tp[depth][1]);
}

int main()
{
	fastip; sws;
	memset(cache, -1, sizeof cache);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tp[i][0] >> tp[i][1];
	}
	cout << dp(0);
}