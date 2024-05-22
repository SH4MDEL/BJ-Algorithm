#include <iostream>
#include <string>
#include <tuple>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int a, b, n, m;
int field[110][110];
tuple<int, int, int> robot[110];
tuple<int, int, int> query[110];
constexpr int dx[] = { 1, 0, -1, 0 };
constexpr int dy[] = { 0, -1, 0, 1 };

int main()
{
	fastip; sws;

	cin >> a >> b >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int x, y, z;
		char c;
		cin >> x >> y >> c;
		if (c == 'E') z = 0;
		if (c == 'S') z = 1;
		if (c == 'W') z = 2;
		if (c == 'N') z = 3;
		robot[i] = { x, y, z };
		field[x][y] = i;
	}
	for (int i = 1; i <= m; ++i) {
		int x, y, z;
		char c;
		cin >> x >> c >> z;
		if (c == 'L') y = 0;
		if (c == 'R') y = 1;
		if (c == 'F') y = 2;
		query[i] = { x, y, z };
	}
	string ans;
	[&]() {
		for (int i = 1; i <= m; ++i) {
			auto [index, q, l] = query[i];
			auto [x, y, z] = robot[index];
			for (int i = 0; i < l; ++i) {
				if (q == 0) z = (z + 3) % 4;
				if (q == 1) z = (z + 1) % 4;
				if (q == 2) {
					int nx = x + dx[z];
					int ny = y + dy[z];
					if (nx == 0 || nx == a + 1 || ny == 0 || ny == b + 1) {
						ans = "Robot " + to_string(index) + " crashes into the wall";
						return;
					}
					if (field[nx][ny]) {
						ans = "Robot " + to_string(index) + " crashes into robot " + to_string(field[nx][ny]);
						return;
					}
					field[x][y] = 0;
					x = nx, y = ny;
					field[x][y] = index;
				}
				robot[index] = { x, y, z };
			}
		}
	}();
	if (ans.empty()) ans = "OK";
	cout << ans;
}