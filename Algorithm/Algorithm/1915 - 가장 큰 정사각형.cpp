#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;
bool map[1010][1010];
int cache[1010][1010];

int main()
{
	fastip; sws;

	cin >> n >> m;
	string s;
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		for (int j = 1; j <= m; ++j) {
			map[i][j] = s[j - 1] - '0';
		}
	}
	int maximum = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!map[i][j]) continue;
			if (!cache[i - 1][j] || !cache[i][j - 1] || !cache[i - 1][j - 1]) {
				cache[i][j] = 1;
				maximum = max(maximum, cache[i][j]);
				continue;
			}
			cache[i][j] = min({cache[i - 1][j], cache[i][j - 1], cache[i - 1][j - 1]}) + 1;
			maximum = max(maximum, cache[i][j]);
		}
	}
	cout << maximum * maximum;
}