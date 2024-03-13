#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int num[20][200200];
int m, q;

int main()
{
	fastip; sws;

	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> num[0][i];
	}
	for (int i = 1; i <= 19; ++i) {
		for (int j = 1; j <= m; ++j) {
			num[i][j] = num[i - 1][num[i - 1][j]];
		}
	}
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		int n, x;
		cin >> n >> x;
		int counter = 0;
		while (n) {
			if (n % 2) x = num[counter][x];
			n /= 2;
			++counter;
		}
		cout << x << endl;
	}
}