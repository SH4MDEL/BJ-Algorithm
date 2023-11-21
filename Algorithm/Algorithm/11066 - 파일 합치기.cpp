#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int t, k;
vector<int> v;
int cache[510][510];	// i~j까지 합치는데 드는 최소비용
int sum[510];

int dp(int s, int e)
{
	if (s == e) return 0;
	if (s + 1 == e) return cache[s][e] = v[s] + v[e];
	if (cache[s][e] != -1) return cache[s][e];

	int minimum = inf;
	for (int i = s; i < e; ++i) {
		minimum = min(minimum, dp(s, i) + dp(i + 1, e) + sum[e] - sum[s - 1]);
	}
	return cache[s][e] = minimum;
}

int main()
{
	fastip; sws;

	cin >> t;
	for (int i = 0; i < t; ++i) {
		memset(cache, -1, sizeof(int) * 510 * 510);
		cin >> k;
		v.clear();
		v.resize(k + 1);
		for (int i = 1; i <= k; ++i) {
			cin >> v[i];
		}
		for (int i = 1; i <= k; ++i) {
			sum[i] = sum[i - 1] + v[i];
		}

		cout << dp(1, k) << endl;

	}
}