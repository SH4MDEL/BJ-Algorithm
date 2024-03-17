#include <iostream>
#include <string>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int t, n, m, x, y;

int main()
{
	fastip; sws;

	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> m >> n >> x >> y;

		bool can = false;
		int a = 0, b = 0;
		for (int j = 0; j < n; ++j) {
			if ((j * n + (y - x)) % m == 0) {
				can = true;
				b = j;
				a = (j * n + (y - x)) / m;
				break;
			}
		}
		for (int j = 0; j < m; ++j) {
			if ((j * m + (x - y)) % n == 0) {
				can = true;
				a = j;
				b = (j * m + (x - y)) / n;
				break;
			}
		}
		if (can) cout << a * m + x << endl;
		else cout << -1 << endl;
	}
}