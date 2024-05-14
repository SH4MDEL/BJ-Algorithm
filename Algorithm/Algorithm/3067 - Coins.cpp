#include <iostream>
#include <algorithm>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int t, n, m;
int coin[22];
int cache[10101];

int main()
{
	fastip; sws;

	cin >> t;
	while (t--) {
		memset(cache, 0, sizeof cache);
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> coin[i];
		}
		cin >> m;
		cache[0] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = coin[i]; j <= m; ++j) {
				cache[j] += cache[j - coin[i]];
			}
		}
		cout << cache[m] << endl;
	}
}