#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int cache[210][110];
int n, m, k;

void search(string& s, int a, int z, int c)
{
	if (s.length() == n + m) return;

	if (z == 0 || c <= cache[a + z - 1][a - 1]) {
		s += "a";
		search(s, a - 1, z, c);
		return;
	}
	s += "z";
	search(s, a, z - 1, c - cache[a + z - 1][a - 1]);
	return;
}

int main()
{
	fastip; sws;

	cin >> n >> m >> k;
	for (int i = 1; i <= n + m; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i == j || j == 0) {
				cache[i][j] = 1;
				continue;
			}
			cache[i][j] = cache[i - 1][j - 1] + cache[i - 1][j];
			if (cache[i][j] > 1'000'000'000) cache[i][j] = 1'000'000'000;
		}
	}
	if (cache[n + m][n] < k) cout << -1;
	else {
		string s; search(s, n, m, k);
		cout << s;
	}

}