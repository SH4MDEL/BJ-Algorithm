#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

int n, ans, maximum = -inf;
vector<ll> v;

bool search(ll start, ll mid, ll end)
{
	if (v[mid] >= v[start] && v[mid] >= v[end]) return false;
	if (v[mid] < v[start] && v[mid] < v[end]) return true;
	if (v[end] > v[start]) {
		if ((v[end] - v[mid]) * (mid - start) <= (v[mid] - v[start]) * (end - mid)) {
			return false;
		}
	}
	else {
		if ((v[mid] - v[end]) * (mid - start) >= (v[start] - v[mid]) * (end - mid)) {
			return false;
		}
	}
	return true;
}

int main()
{
	fastip; sws;
	cin >> n;
	v.resize(n);
	for (auto& e : v) cin >> e;
	for (ll i = 0; i < n; ++i) {
		ans = 0;
		for (ll j = i - 1; j >= 0; --j) {
			bool can = true;
			for (ll m = i - 1; m > j; --m) {
				if (!search(j, m, i)) {
					can = false;
					break;
				}
			}
			if (can) ++ans;
		}
		for (ll j = i + 1; j < n; ++j) {
			bool can = true;
			for (ll m = i + 1; m < j; ++m) {
				if (!search(i, m, j)) {
					can = false;
					break;
				}
			}
			if (can) ++ans;
		}
		maximum = max(maximum, ans);
	}
	cout << maximum;
}