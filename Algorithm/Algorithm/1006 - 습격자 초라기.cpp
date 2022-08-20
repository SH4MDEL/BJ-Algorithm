#include <iostream>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int t, n, w;

int area[10010][2];
int cache[10010][4][4];

inline int judge(int state, int laststate)
{
	if (state == 0) {
		if (laststate == 0 || laststate == 1 || laststate == 2) {
			return inf;
		}
		if (laststate == 3) {
			return 0;
		}
	}
	if (state == 1) {
		if (laststate == 0 || laststate == 1) {
			return inf;
		}
		if (laststate == 2) {
			return 0;
		}
		if (laststate == 3) {
			return 1;
		}
	}
	if (state == 2) {
		if (laststate == 0 || laststate == 2) {
			return inf;
		}
		if (laststate == 1) {
			return 0;
		}
		if (laststate == 3) {
			return 1;
		}
	}
	if (state == 3) {
		if (laststate == 0) {
			return 0;
		}
		if (laststate == 3 && w < area[n - 1][0] + area[n - 1][1]) {
			return 2;
		}
		return 1;
	}
}

int dp(int depth, int state, int laststate)
{
	if (depth == n - 1) {
		return judge(state, laststate);
	}
	if (cache[depth][state][laststate] != -1) return cache[depth][state][laststate];

	if (state == 0) {
		return cache[depth][state][laststate] = dp(depth + 1, 3, laststate);
	}
	if (state == 1) {
		if (w >= area[depth][1] + area[depth + 1][1]) {
			return cache[depth][state][laststate] = dp(depth + 1, 2, laststate) + 1;
		}
		return cache[depth][state][laststate] = dp(depth + 1, 3, laststate) + 1;
	}
	if (state == 2) {
		if (w >= area[depth][0] + area[depth + 1][0]) {
			return cache[depth][state][laststate] = dp(depth + 1, 1, laststate) + 1;
		}
		return cache[depth][state][laststate] = dp(depth + 1, 3, laststate) + 1;
	}
	if (state == 3) {
		int minq = inf;
		// 이번 구역을 일자로 커버 성공
		if (w >= area[depth][0] + area[depth][1]) {
			minq = min(minq, dp(depth + 1, 3, laststate) + 1);
		}
		// 일자로 커버한것이 최적해라고 할 수는 없다.
		// 좌우 커버는 되냐?
		if (w >= area[depth][0] + area[depth + 1][0] && w >= area[depth][1] + area[depth + 1][1]) {
			minq = min(minq, dp(depth + 1, 0, laststate) + 2);
		}
		// 위만이라도 되냐?
		else if (w >= area[depth][0] + area[depth + 1][0]) {
			minq = min(minq, dp(depth + 1, 1, laststate) + 2);
		}
		// 아래만이라도 되냐?
		else if (w >= area[depth][1] + area[depth + 1][1]) {
			minq = min(minq, dp(depth + 1, 2, laststate) + 2);
		}
		else {
			minq = min(minq, dp(depth + 1, 3, laststate) + 2);
		}
		return cache[depth][state][laststate] = minq;
	}
}

int main()
{
	fastip; sws;

	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n >> w;
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < 4; ++k) {
				for (int l = 0; l < 4; ++l) {
					cache[j][k][l] = -1;
				}
			}
		}
		for (int j = 0; j < n; ++j) {
			cin >> area[j][0];
		}
		for (int j = 0; j < n; ++j) {
			cin >> area[j][1];
		}

		if (n == 1) {
			if (w >= area[0][0] + area[0][1]) cout << "1" << endl;
			else cout << "2" << endl;
		}
		else {
			int minq = inf;
			if (w >= area[0][0] + area[0][1]) {
				minq = min(minq, dp(1, 3, 3) + 1);
			}

			if (w >= area[n - 1][0] + area[0][0] && w >= area[n - 1][1] + area[0][1]) {
				minq = min(minq, dp(1, 3, 0) + 2);
			}
			if (w >= area[n - 1][0] + area[0][0]) {
				if (w >= area[0][1] + area[1][1]) {
					minq = min(minq, dp(1, 2, 1) + 2);
				}
				else {
					minq = min(minq, dp(1, 3, 1) + 2);
				}
			}
			if (w >= area[n - 1][1] + area[0][1]) {
				if (w >= area[0][0] + area[1][0]) {
					minq = min(minq, dp(1, 1, 2) + 2);
				}
				else {
					minq = min(minq, dp(1, 3, 2) + 2);
				}
			}

			if (w >= area[0][0] + area[1][0] && w >= area[0][1] + area[1][1]) {
				minq = min(minq, dp(1, 0, 3) + 2);
			}
			else if (w >= area[0][0] + area[1][0]) {
				minq = min(minq, dp(1, 1, 3) + 2);
			}
			else if (w >= area[0][1] + area[1][1]) {
				minq = min(minq, dp(1, 2, 3) + 2);
			}
			else {
				minq = min(minq, dp(1, 3, 3) + 2);
			}
			cout << minq << endl;
		}
	}
}