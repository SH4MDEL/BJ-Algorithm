#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 1987654321 
#define endl "\n"
using namespace std;

int n;
int cache[510][510];
int matrix[510][2];

int dp(int s, int e)
{
	if (s == e) return 0;
	if (cache[s][e] != -1) return cache[s][e];
	if (s + 1 == e) return cache[s][e] = matrix[s][0] * matrix[s][1] * matrix[e][1];

	int minimum = inf;
	for (int m = s; m < e; ++m) {
		minimum = min(minimum, dp(s, m) + dp(m + 1, e) + matrix[s][0] * matrix[m][1] * matrix[e][1]);
	}
	return cache[s][e] = minimum;
}

int main()
{
	fastip; sws;

	memset(cache, -1, sizeof(int) * 510 * 510);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> matrix[i][0] >> matrix[i][1];
	}

	cout << dp(1, n);
}