#include <iostream>
#include <string>
#include <deque>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

int n, m, t;
deque<int> d[55];
bool deleted[55][55], run;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main()
{
	fastip; sws;
	cin >> n >> m >> t;
	for (int i = 0; i < n; ++i) {
		d[i].resize(m);
		for (int j = 0; j < m; ++j) {
			cin >> d[i][j];
		}
	}
	for (int i = 0; i < t; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = a; j <= n; j += a) {
			if (b == 0) {
				for (int k = 0; k < c; ++k) {
					d[j - 1].push_front(d[j - 1].back());
					d[j - 1].pop_back();
				}
			}
			if (b == 1) {
				for (int k = 0; k < c; ++k) {
					d[j - 1].push_back(d[j - 1].front());
					d[j - 1].pop_front();
				}
			}
		}
		memset(deleted, false, sizeof deleted);
		run = false;
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				for (int l = 0; l < 4; ++l) {
					int ny = j + dy[l];
					int nx = k + dx[l];
					if (ny == -1) continue;
					if (nx == -1) nx = m - 1;
					if (ny == n) continue;
					if (nx == m) nx = 0;

					if (d[j][k] != -1 && d[j][k] == d[ny][nx]) {
						deleted[j][k] = true;
						deleted[ny][nx] = true;
						run = true;
					}
				}
			}
		}
		if (run) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < m; ++k) {
					if (deleted[j][k]) {
						d[j][k] = -1;
					}
				}
			}
		}
		else {
			double sum = 0.0, count = 0.0;
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < m; ++k) {
					if (d[j][k] != -1) {
						sum += static_cast<double>(d[j][k]);
						count += 1.0;
					}
				}
			}
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < m; ++k) {
					if (d[j][k] == -1) continue;
					if (d[j][k] == static_cast<int>(sum / count) &&
						(static_cast<int>(sum) % static_cast<int>(count) == 0)) {
						continue;
					}
					else if (d[j][k] > sum / count) {
						d[j][k] -= 1;
					}
					else {
						d[j][k] += 1;
					}
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (d[i][j] != -1) {
				sum += d[i][j];
			}
		}
	}
	cout << sum;
}