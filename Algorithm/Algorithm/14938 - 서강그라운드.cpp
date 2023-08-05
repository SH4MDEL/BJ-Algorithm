#include <iostream>
#include <vector>
#include <stack>
#include <list>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m, r;
int t[101][101];
int item[101];

int main()
{
	fastip; sws;

	cin >> n >> m >> r;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			t[i][j] = inf;
		}
	}

	for (int i = 1; i <= n; ++i) {
		cin >> item[i];
	}
	for (int i = 0; i < r; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		t[a][b] = c;
		t[b][a] = c;
	}

	for (int m = 1; m <= n; ++m) {
		for (int s = 1; s <= n; ++s) {
			for (int e = 1; e <= n; ++e) {
				t[s][e] = min(t[s][e], t[s][m] + t[m][e]);
			}
		}
	}

	int maximum = -inf;

	for (int i = 1; i <= n; ++i) {
		int sum = 0;
		for (int j = 1; j <= n; ++j) {
			if (i == j) {
				sum += item[j];
			}
			else if (t[i][j] <= m) {
				sum += item[j];
			}
		}
		maximum = max(maximum, sum);
	}
	cout << maximum;
}