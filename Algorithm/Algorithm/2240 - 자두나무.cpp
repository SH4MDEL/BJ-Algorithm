#include <iostream>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

int t, w;
int num[1010];
int cache[1010][40][2];

int dp(int depth, int moving, int pos)
{
	if (depth == t) return 0;
	if (cache[depth][moving][pos] != -1) 
		return cache[depth][moving][pos];

	if (num[depth] == pos) return cache[depth][moving][pos] = 
		dp(depth + 1, moving, pos) + 1;
	if (moving == w) return cache[depth][moving][pos] = 
		dp(depth + 1, moving, pos);

	return cache[depth][moving][pos] = 
		max(dp(depth + 1, moving, pos), dp(depth + 1, moving + 1, 1 - pos) + 1);
}

int main()
{
	fastip; sws;

	memset(cache, -1, sizeof cache);

	cin >> t >> w;
	for (int i = 0; i < t; ++i) {
		cin >> num[i];
		--num[i];
	}
	cout << dp(0, 0, 0);
}