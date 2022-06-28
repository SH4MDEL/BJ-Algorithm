#include <iostream>
#define endl "\n"
using namespace std;

int N, M;

long long cache[110][110];

long long comb(int n, int m)
{
	if (cache[n][m] != -1) {
		return cache[n][m];
	}
	if (n == m || m == 0) {
		return cache[n][m] = 1LL;
	}
	return cache[n][m] = comb(n - 1, m - 1) + comb(n - 1, m);
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	for (int i = 0; i < 110; ++i) {
		for (int j = 0; j < 110; ++j) {
			cache[i][j] = -1;
		}
	}

	cin >> N >> M;
	cout << comb(N, M) << endl;
	
}