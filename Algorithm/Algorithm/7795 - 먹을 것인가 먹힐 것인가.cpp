#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

int t, n, m;

int main()
{
	fastip; sws;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector a(n, 0);
		vector b(m, 0);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < m; ++i) cin >> b[i];
		sort(b.begin(), b.end());
		ll ans = 0;
		for (int i = 0; i < n; ++i) {
			auto upper = upper_bound(b.begin(), b.end(), a[i] - 1);
			ans += upper - b.begin();
		}
		cout << ans << endl;
	}
}