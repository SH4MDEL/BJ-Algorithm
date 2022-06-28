#include <iostream>
#define endl "\n"
#define inf 987654321
using namespace std;

int n;
int triangle[510][510];
int cache[510][510];

int solve(int x, int y, int floor)
{
	if (floor == n) {
		return 0;
	}
	if (cache[x][y] != -1) {
		return cache[x][y];
	}
	int left = solve(x, y + 1, floor + 1) + triangle[x][y];
	int right = solve(x + 1, y + 1, floor + 1) + triangle[x][y];
	if (left < right) {
		return cache[x][y] = right;
	}
	else {
		return cache[x][y] = left;
	}
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	for (int i = 0; i < 510; ++i) {
		for (int j = 0; j < 510; ++j) {
			cache[i][j] = -1;
		}
	}

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			cin >> triangle[j][i];
		}
	}
	cout << solve(0, 0, 0) << endl;
	
}