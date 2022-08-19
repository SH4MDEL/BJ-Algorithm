#include <iostream>
#include <algorithm>
#include <cstring>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;
int cache[2020][2020];
int num[2020];

int solve(int s, int e)
{
	if (s > e) return 1;

	if (cache[s][e] != -1) return cache[s][e];

	if (num[s] != num[e]) return cache[s][e] = 0;
	
	return cache[s][e] = solve(s + 1, e - 1);
}

int main()
{
	fastip; sws;
	cin >> n;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	for (int i = 0; i < n; ++i) {
		cache[i][i] = 1;
	}
	for (int i = 1; i < n; ++i) {
		if (num[i - 1] == num[i]) {
			cache[i - 1][i] = 1;
		}
	}
	int a, b;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		cout << solve(a - 1, b - 1) << endl;;
	}
}