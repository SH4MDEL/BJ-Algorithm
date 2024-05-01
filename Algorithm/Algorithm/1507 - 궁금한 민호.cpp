#include <iostream>
#include <algorithm>
#include <string>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int n, ans;
int field[25][25];
bool deleted[25][25];

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> field[i][j];
		}
	}

	for (int m = 0; m < n; ++m) {
		for (int s = 0; s < n; ++s) {
			for (int e = 0; e < n; ++e) {
				if (s == e || s == m || m == e) continue;
				if (field[s][e] > (field[s][m] + field[m][e])) {
					cout << -1;
					return 0;
				}
				if (field[s][e] == (field[s][m] + field[m][e])) {
					deleted[s][e] = true;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!deleted[i][j]) ans += field[i][j];
		}
	}
	cout << ans / 2;
}