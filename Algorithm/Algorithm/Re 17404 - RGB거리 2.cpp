#include <iostream>
#include <algorithm>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
int cost[1010][3];
int cache[1010][3];

enum Color { R, G, B };

int dp(int depth, Color color, Color sC)
{
	if (depth == n - 1) {
		if (color == sC) return inf;
		return cache[depth][color] = cost[depth][color];
	}
	if (cache[depth][color] != -1) return cache[depth][color];

	return cache[depth][color] = min(
		dp(depth + 1, static_cast<Color>((color + 1) % 3), sC), 
		dp(depth + 1, static_cast<Color>((color + 2) % 3), sC)) + cost[depth][color];
}

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	int minimum = inf;
	for (int i = 0; i < 3; ++i) {
		Color color = static_cast<Color>(i);
		memset(cache, -1, sizeof(cache));
		minimum = min(minimum, dp(0, color, color));
	}
	cout << minimum;
}