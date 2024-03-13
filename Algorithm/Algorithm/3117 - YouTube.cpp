#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, k, m;
int student[100100];
int movie[30][100100];

int main()
{
	fastip; sws;

	cin >> n >> k >> m;
	for (int i = 0; i < n; ++i) {
		cin >> student[i];
	}
	for (int i = 1; i <= k; ++i) {
		cin >> movie[0][i];
	}

	for (int i = 1; i < 30; ++i) {
		for (int j = 1; j <= k; ++j) {
			movie[i][j] = movie[i - 1][movie[i - 1][j]];
		}
	}

	for (int i = 0; i < n; ++i) {
		int target = m - 1;
		int count = 0;
		int ans = student[i];
		while (target) {
			if (target % 2) {
				ans = movie[count][ans];
			}
			target /= 2;
			++count;
		}
		cout << ans << " ";
	}
}