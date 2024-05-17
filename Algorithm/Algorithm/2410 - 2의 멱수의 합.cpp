#include <iostream>
#include <memory.h>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define mod 1'000'000'000
#define ll long long
#define endl "\n"
using namespace std;

ll n;
ll cache[1000100];
vector<ll> power;

int main()
{
	fastip; sws;

	cin >> n;
	power.push_back(1);
	for (int i = 2; i <= n; i *= 2) {
		power.push_back(i);
	}
	cache[0] = 1;
	for (int i = 0; i < power.size(); ++i) {
		for (ll j = power[i]; j <= n; ++j) {
			cache[j] += cache[j - power[i]];
			cache[j] %= mod;
		}
	}
	cout << cache[n];
	
}