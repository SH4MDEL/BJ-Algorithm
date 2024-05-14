#include <iostream>
#include <deque>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define endl "\n"
using namespace std;

int n, k, ans;
deque<int> d;
deque<bool> robot;

bool check()
{
	int counter = 0;
	for (const auto& e : d) if (e == 0) ++counter;
	if (counter >= k) return false;
	return true;
}

int main()
{
	fastip; sws;

	cin >> n >> k;
	d.resize(n * 2);
	robot.resize(n * 2);
	for (int i = 0; i < n * 2; ++i) {
		cin >> d[i];
		robot[i] = false;
	}

	while (check()) {
		++ans;
		d.push_front(d.back());
		d.pop_back();
		robot.push_front(robot.back());
		robot.pop_back();
		if (robot[n - 1]) robot[n - 1] = false;
		for (int i = n - 1; i >= 0; --i) {
			if (d[i + 1] && robot[i] && !robot[i + 1]) {
				robot[i] = false;
				if (i + 1 != n - 1) robot[i + 1] = !robot[i + 1];
				--d[i + 1];
			}
		}
		if (d[0]) {
			robot[0] = true;
			--d[0];
		}
	}
	cout << ans;
}