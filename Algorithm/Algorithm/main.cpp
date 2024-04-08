#include <iostream>
#include <ranges>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

ll n, k;

int main() 
{
	fastip; sws;

	cin >> n >> k;
	auto ans = *ranges::lower_bound(
		views::iota(1LL, n * n + 1), k, ranges::less{}, [&](ll num) {
			ll count = 0LL;
			for (ll i = 1; i <= min(num, n); ++i) {
				count += min((num) / i, n);
			}
			return count;
		});
	cout << ans;
}