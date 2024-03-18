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

int cache[35][35];

int t, n, m;

int main()
{
	fastip; sws;

	for (int i = 1; i <= 30; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0 || j == i) {
				cache[i][j] = 1;
				continue;
			}
			cache[i][j] = cache[i - 1][j] + cache[i - 1][j - 1];
		}
	}

	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << cache[m][n] << endl;
	}
}