#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'000;
using namespace std;

int n;
int visited[10][101][1 << 10];

int dp(int now, int depth, int key)
{
	if (depth == n) {
		if (key == (1 << 10) - 1) return 1;
		return 0;
	}
	if (visited[now][depth][key] != -1) return visited[now][depth][key];

	int ans = 0;
	if (now == 0) {
		ans += dp(now + 1, depth + 1, key | (1 << (now + 1)));
		return visited[now][depth][key] = ans % mod;
	}
	if (now == 9) {
		ans += dp(now - 1, depth + 1, key | (1 << (now - 1)));
		return visited[now][depth][key] = ans % mod;
	}
	ans += dp(now + 1, depth + 1, key | (1 << (now + 1)));
	ans += dp(now - 1, depth + 1, key | (1 << (now - 1)));
	return visited[now][depth][key] = ans % mod;
}

int main()
{
	fastip; sws;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < (1 << 10); ++k) {
				visited[i][j][k] = -1;
			}
		}
	}
	for (int i = 1; i <= 9; ++i) {
		sum += dp(i, 1, 1 << i);
		sum %= mod;
	}
	cout << sum;
}