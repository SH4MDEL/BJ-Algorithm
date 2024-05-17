#include <iostream>
#include <unordered_map>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

unordered_map<ll, ll> cache;
ll n, p, q, x, y;

ll dp(ll now)
{
	if (now <= 0) return 1;
	return cache[now] = dp(now / p - x) + dp(now / q - y);
}

int main()
{
	fastip; sws;

	cin >> n >> p >> q >> x >> y;
	cout << dp(n);
}