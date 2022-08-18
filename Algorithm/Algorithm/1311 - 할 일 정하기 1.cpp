#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
int work[1 << 20];
int price[20][20];

int dp(int depth, int key)
{
	if (depth >= n) return 0;
	if (work[key] != -1) return work[key];
	int minp = inf;
	for (int i = 0; i < n; ++i) {
		if ((key & (1 << i)) == 0) {
			minp = min(minp, dp(depth + 1, (key | (1 << i))) + price[depth][i]);
		}
	}
	return work[key] = minp;
}

int main()
{
	fastip; sws;
	cin >> n;
	for (int i = 0; i < (1 << n); ++i) {
		work[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> price[i][j];
		}
	}
	cout << dp(0, 0);
}