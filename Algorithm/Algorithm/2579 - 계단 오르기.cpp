#include <iostream>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'000;
using namespace std;

int n;
int stair[330];
int cache[330][2];

int dp(int depth, int status)
{
	if (depth > n) return -inf;
	if (cache[depth][status] != 0) return cache[depth][status];
	if (depth == n) return cache[depth][status] = stair[depth];

	int maxq = -inf;
	maxq = dp(depth + 2, 1) + stair[depth];
	if (status != 2) maxq = max(maxq, dp(depth + 1, status + 1) + stair[depth]);
	return cache[depth][status] = maxq;
}

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> stair[i];
	}
	cout << max(dp(1, 1), dp(2, 1));
}