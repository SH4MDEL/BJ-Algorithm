#include <iostream>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int length, width, height;
int n, ans;
int cube[20];

bool devide(int l, int w, int h)
{
	if (l == 0 || w == 0 || h == 0) return true;

	for (int i = 19; i >= 0; --i) {
		if (cube[i] == 0) continue;

		int now = 1 << i;
		if (now <= l && now <= w && now <= h) {
			--cube[i];
			++ans;
			return (devide(l, w, h - now) && 
				devide(now, w - now, now) && devide(l - now, w, now));
		}
	}
	return false;
}

int main()
{
	fastip; sws;

	cin >> length >> width >> height >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		cube[a] = b;
	}
	if (devide(length, width, height)) {
		cout << ans;
	}
	else {
		cout << -1;
	}
}