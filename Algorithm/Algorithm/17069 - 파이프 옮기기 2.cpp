#include <iostream>
#include <tuple>
#include <vector>
#include <optional>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

typedef tuple<int, int> Position;
int n;
int field[40][40];
vector cache(40, vector(40, vector(3, optional<ll>())));

ll dp(Position pos, int direction)
{
	auto [ny, nx] = pos;
	if (ny == n && nx == n) return 1LL;
	if (cache[ny][nx][direction].has_value()) return cache[ny][nx][direction].value();

	ll ans = 0LL;
	if (ny != n && nx != n && field[ny + 1][nx + 1] != 1 &&
		field[ny + 1][nx] != 1 && field[ny][nx + 1] != 1) {
		ans += dp({ ny + 1, nx + 1 }, 2);
	}
	if (direction != 0 && ny != n && field[ny + 1][nx] != 1) {
		ans += dp({ ny + 1, nx }, 1);
	}
	if (direction != 1 && nx != n && field[ny][nx + 1] != 1) {
		ans += dp({ ny, nx + 1 }, 0);
	}
	return cache[ny][nx][direction].emplace(ans);
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