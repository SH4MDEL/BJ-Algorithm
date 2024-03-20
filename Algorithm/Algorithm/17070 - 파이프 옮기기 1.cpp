#include <iostream>
#include <tuple>
#include <vector>
#include <optional>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

typedef tuple<int, int> Position;
int n;
int field[20][20];
vector cache(20, vector(20, vector(3, optional<int>())));

int dp(Position pos, int direction)
{
	auto [ey, ex] = pos;
	if (ey == n && ex == n) return 1;
	if (cache[ey][ex][direction].has_value()) return cache[ey][ex][direction].value();

	int ans = 0;
	int ny = ey + 1;
	int nx = ex + 1;
	if (ny != 0 && ny != n + 1 && nx != 0 && nx != n + 1 && 
		field[ey][nx] != 1 &&
		field[ny][ex] != 1 &&
		field[ny][nx] != 1) {
		ans += dp({ ny, nx }, 1);
	}
	if (direction != 0 && ny != 0 && ny != n + 1 && field[ny][ex] != 1) {
		ans += dp({ ny, ex }, 2);
	}
	if (direction != 2 && nx != 0 && nx != n + 1 && field[ey][nx] != 1) {
		ans += dp({ ey, nx }, 0);
	}
	return cache[ey][ex][direction].emplace(ans);
}

int main()
{
	fastip; sws;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> field[i][j];
		}
	}
	cout << dp({ 1, 2 }, 0);
}