#include <iostream>
#include <unordered_map>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

unordered_map<ll, ll> cache;
ll n, p, q;

ll dp(ll now)
{
	if (cache.count(now)) return cache[now];
	return cache[now] = dp(now / p) + dp(now / q);
}

int main()
{
	fastip; sws;

	cache[0] = 1;
	cin >> n >> p >> q;
	cout << dp(n);
}