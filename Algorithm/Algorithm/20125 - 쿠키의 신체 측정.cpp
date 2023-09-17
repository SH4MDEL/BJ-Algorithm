#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <unordered_set>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
char map[1010][1010];
pair<int, int> heart;
int ans[5];

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (map[i][j] == '*' and
				map[i - 1][j] == '*' and
				map[i + 1][j] == '*' and
				map[i][j - 1] == '*' and
				map[i][j + 1] == '*') {
				heart.first = i;
				heart.second = j;
			}
		}
	}
	for (int i = heart.second - 1; i >= 0; --i) {
		if (map[heart.first][i] != '*') {
			ans[0] = heart.second - 1 - i;
			break;
		}
	}
	for (int i = heart.second + 1; i <= n + 1; ++i) {
		if (map[heart.first][i] != '*') {
			ans[1] = i - heart.second - 1;
			break;
		}
	}
	for (int i = heart.first + 1; i <= n; ++i) {
		if (map[i][heart.second] != '*') {
			ans[2] = i - heart.first - 1;
			break;
		}
	}
	for (int i = heart.first + ans[2] + 1; i <= n + 1; ++i) {
		if (map[i][heart.second - 1] != '*') {
			ans[3] = i - heart.first - ans[2] - 1;
			break;
		}
	}
	for (int i = heart.first + ans[2] + 1; i <= n + 1; ++i) {
		if (map[i][heart.second + 1] != '*') {
			ans[4] = i - heart.first - ans[2] - 1;
			break;
		}
	}

	cout << heart.first << " " << heart.second << endl;
	for (int i = 0; i < 5; ++i) {
		cout << ans[i] << " ";
	}
}