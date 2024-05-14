#include <iostream>
#include <algorithm>
#include <string>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int h, w, ans;
int block[550];
int lft[550], rgt[550];

int main()
{
	fastip; sws;

	cin >> h >> w;
	for (int i = 0; i < w; ++i) {
		cin >> block[i];
	}
	for (int m = 0; m < w; ++m) {
		for (int l = m - 1; l >= 0; --l) {
			if (block[l] > block[m]) {
				lft[m] = max(lft[m], block[l]);
			}
		}
		for (int r = m + 1; r < w; ++r) {
			if (block[r] > block[m]) {
				rgt[m] = max(rgt[m], block[r]);
			}
		}
	}
	for (int i = 0; i < w; ++i) {
		int minimum = min(lft[i], rgt[i]);
		if (minimum > block[i]) {
			ans += minimum - block[i];
		}
	}
	cout << ans;
}