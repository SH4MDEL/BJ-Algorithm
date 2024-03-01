#include <iostream>
#include <stack>
#include <algorithm>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

bool map[110][110];
int g;

constexpr int dx[] = { 1, 0, -1, 0 };
constexpr int dy[] = { 0, -1, 0, 1 };

void create(int x, int y, int depth, stack<int> before)
{
	if (depth == g) return;

	stack<int> curve(before);
	while (!before.empty())
	{
		int dir = ((before.top() + 1) % 4); before.pop();
		curve.push(dir);
		x += dx[dir];
		y += dy[dir];
		map[y][x] = true;
	}
	create(x, y, depth + 1, curve);
}

int search()
{
	int ans = 0;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (map[i][j] && map[i + 1][j] && map[i + 1][j + 1] && map[i][j + 1]) {
				++ans;
			}
		}
	}
	return ans;
}

int main()
{
	fastip; sws;

	memset(map, false, sizeof(bool) * 110 * 110);
	int n, x, y, d;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> d >> g;
		map[y][x] = true;

		stack<int> s;
		s.push(d);

		x += dx[d];
		y += dy[d];
		map[y][x] = true;
		
		create(x, y, 0, s);
	}
	cout << search();
}