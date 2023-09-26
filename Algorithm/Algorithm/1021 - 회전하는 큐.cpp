#include <iostream>
#include <deque>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;
deque<int> d;
deque<int> g;

int main()
{
	fastip; sws;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		d.push_back(i);
	}
	g.resize(m);
	for (int i = 0; i < m; ++i) {
		int num;
		cin >> num;
		g[i] = num;
	}
	int ans = 0;
	while (!g.empty()) {
		int goal = g.front(); g.pop_front();
		int i = 0;
		for (auto itr = d.begin(); itr != d.end(); ++itr) {
			if (*itr == goal) {
				break;
			}
			++i;
		}
		int j = 0;
		for (auto itr = d.rbegin(); itr != d.rend(); ++itr) {
			if (*itr == goal) {
				break;
			}
			++j;
		}
		if (i <= j) {
			while (d.front() != goal) {
				d.push_back(d.front());
				d.pop_front();
				++ans;
			}
			d.pop_front();
		}
		else {
			while (d.front() != goal) {
				d.push_front(d.back());
				d.pop_back();
				++ans;
			}
			d.pop_front();
		}
	}
	cout << ans << endl;
}