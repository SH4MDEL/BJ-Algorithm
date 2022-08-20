#include <iostream>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
int house[1010][3];
int cache[1010][3];

int dp(int depth, int color)
{
	if (depth == n) return 0;
	if (cache[depth][color] != 0) return cache[depth][color];

	if (color == 0) {
		return cache[depth][color] = min(dp(depth + 1, 1) + house[depth][color], dp(depth + 1, 2) + house[depth][color]);
	}
	if (color == 1) {
		return cache[depth][color] = min(dp(depth + 1, 0) + house[depth][color], dp(depth + 1, 2) + house[depth][color]);
	}
	if (color == 2) {
		return cache[depth][color] = min(dp(depth + 1, 0) + house[depth][color], dp(depth + 1, 1) + house[depth][color]);
	}
}

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> house[i][j];
		}
	}
	int minq = inf;
	for (int i = 0; i < 3; ++i) {
		minq = min(minq, dp(0, i));
	}
	cout << minq << endl;
}