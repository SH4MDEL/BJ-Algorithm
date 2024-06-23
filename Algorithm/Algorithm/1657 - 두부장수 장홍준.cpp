#include <iostream>
#include <string>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int n, m;
int cache[15 * 15][1 << 14];
char field[15 * 15];

int GetCost(char c1, char c2)
{
	if (c1 < c2) swap(c1, c2);
	if (c1 == 'F') {
		if (c2 == 'F') return 0;
		return 1;
	}
	if (c1 == 'D') {
		if (c2 == 'D' || c2 == 'C') return 2;
		if (c2 == 'B') return 3;
		return 5;
	}
	if (c1 == 'C') {
		if (c2 == 'C') return 3;
		if (c2 == 'B') return 4;
		return 7;
	}
	if (c1 == 'B') {
		if (c2 == 'B') return 6;
		return 8;
	}
	return 10;
}

int dp(int depth, int key)
{
	if (depth >= n * m) return 0;
	if (cache[depth][key] != -1) return cache[depth][key];

	int y = depth / m, x = depth % m;
	auto& result = cache[depth][key];
	result = max(dp(depth + 1, key >> 1), result);
	if (x + 1 != m && !(key & 0b11)) 
		result = max(dp(depth + 2, key >> 2) + GetCost(field[depth], field[depth + 1]), result);
	if (y + 1 != n && !(key & 0b1))
		result = max(dp(depth + 1, (key >> 1) | (1 << (m - 1))) + GetCost(field[depth], field[depth + m]), result);

	return result;
}

int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			field[i * m + j] = s[j];
		}
	}
	memset(cache, -1, sizeof cache);
	cout << dp(0, 0);
}