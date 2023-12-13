#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 10007
using namespace std;

int n;
int cache[10][1010];

int dp(int s, int i)
{
	if (cache[s][i] != -1) return cache[s][i];

	int ans = 0;
	for (int j = s; j <= 9; ++j) {
		ans = ((ans % mod) + (dp(j, i - 1) % mod) % mod);
	}
	return cache[s][i] = ans;
}

int main()
{
	fastip; sws;

	memset(cache, -1, sizeof(int) * 10 * 1010);
	for (int i = 0; i < 10; ++i) {
		cache[i][1] = 1;
	}
	cin >> n;
	cout << dp(0, n + 1);

}