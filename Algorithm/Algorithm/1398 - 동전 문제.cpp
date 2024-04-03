#include <iostream>
#include <unordered_map>
#include <tuple>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321LL
#define mod 1'000'000'003
#define endl "\n"
#define ll long long
using namespace std;

int t;
ll n;
unordered_map<ll, ll> um;

ll calc(ll num)
{
	ll ans = 1;
	while (num /= 10) { ++ans; }
	return ans;
}

ll Pow(ll num, ll k) {
	if (!k) return 1LL;
	ll ans = num;
	while (--k) {
		ans *= num;
	}
	return ans;
}

ll dp(ll num)
{
	if (num == 0LL) return 0LL;
	if (num < 0LL) return inf;
	if (um.count(num)) return um[num];
	ll digit = calc(num);
	if (digit == 1LL) return um[num] = num;

	ll lcoin = Pow(10L, digit - 1LL);
	ll rcoin = 25LL * Pow(100L, digit / 2LL - 1LL);

	return um[num] = min(dp(num - lcoin), dp(num - rcoin)) + 1LL;
}

int main()
{
	fastip; sws;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp(n) << endl;
	}
}