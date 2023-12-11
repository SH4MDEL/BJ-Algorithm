#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int l, n, rf, rb;	// 최대 이동 거리, 휴게소 수, 존 속도, 베시 속도(미터당 초)
struct rest {
	int x, c;
	bool maximum;
};
vector<rest> v;

int main()
{
	fastip; sws;

	cin >> l >> n >> rf >> rb;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].x >> v[i].c;
	}
	int maxi = -1;
	for (int i = v.size() - 1; i >= 0; --i) {
		if (maxi < v[i].c) {
			v[i].maximum = true;
			maxi = v[i].c;
		}
	}
	long long ans = 0;
	long long gap = rf - rb;
	long long before = 0;
	for (const auto& e : v) {
		if (e.maximum) {
			ans += e.c * gap * (e.x - before);
			before = e.x;
		}
	}
	cout << ans;
}