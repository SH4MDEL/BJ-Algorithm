#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m, b;
int map[510][510];
int height[260];
int ans = inf;

int solve(int goal)
{
	int block = b;
	
	int time = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] > goal) {
				time += (map[i][j] - goal) * 2;
				block += map[i][j] - goal;
			}
			else if (map[i][j] < goal) {
				time += goal - map[i][j];
				block -= goal - map[i][j];
			}
		}
	}

	if (block < 0) return inf;
	return time;
}

int main()
{
	fastip; sws;

	int maxheight = -inf;
	int minheight = inf;

	cin >> n >> m >> b;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			maxheight = max(maxheight, map[i][j]);
			minheight = min(minheight, map[i][j]);
		}
	}
	
	for (int i = minheight; i <= maxheight; ++i) {
		height[i] = solve(i);
		ans = min(height[i], ans);
	}
	cout << ans << " ";
	for (int i = maxheight; i >= minheight; --i) {
		if (height[i] == ans) {
			cout << i;
			break;
		}
	}
}
