#include <iostream>
#include <string>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

long double p[3];
long double ans[5];
long double cache[25][50];

int main()
{
	fastip; sws;
	cout << fixed; cout.precision(8);

	for (int i = 0; i < 3; ++i) cin >> p[i];

	cache[0][21] = 1.0;
	for (int i = 1; i <= 20; ++i) {
		for (int j = 1; j <= 41; ++j) {
			cache[i][j] += cache[i - 1][j - 1] * p[0];
			cache[i][j] += cache[i - 1][j + 1] * p[1];
			cache[i][j] += cache[i - 1][j] * p[2];
		}
	}
	for (int j = 0; j <= 41; ++j) {
		int score = 50 * j + 1000 - 50;
		if (score <= 1499) ans[0] += cache[20][j];
		if (1500 <= score && score <= 1999) ans[1] += cache[20][j];
		if (2000 <= score && score <= 2499) ans[2] += cache[20][j];
		if (2500 <= score && score <= 2999) ans[3] += cache[20][j];
		if (3000 <= score) ans[4] += cache[20][j];
	}

	for (int i = 0; i < 5; ++i) {
		cout << ans[i] << endl;
	}
}