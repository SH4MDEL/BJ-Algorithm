#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int city[16][16];
int visited[16][1 << 16];
int n;

int dp(int current, int key)
{
	if (visited[current][key] != -1) return visited[current][key];
	if (key == (1 << n) - 1) {
		if (city[current][0] == 0) return inf;
		return city[current][0];
	}
	int minq = inf;
	for (int i = 0; i < n; ++i) {
		if ((key & (1 << i)) == 0 && city[current][i] != 0) {
			minq = min(minq, dp(i, (key | (1 << i))) + city[current][i]);
		}
	}
	return visited[current][key] = minq;
}

int main()
{
	fastip; sws;
	cin >> n;
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			visited[i][j] = -1;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> city[i][j];
		}
	}
	cout << dp(0, 1);
}
