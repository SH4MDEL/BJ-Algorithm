#include <iostream>
#include <string>
#include <stack>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define mod 1'000'000'000
#define ll long long
#define endl "\n"
using namespace std;

ll cache[1000100];
ll n;

int main()
{
	fastip; sws;

	cin >> n;
	cache[1] = 1;
	if (n >= 0) {
		for (int i = 2; i <= n; ++i) {
			cache[i] = (cache[i - 1] % mod + cache[i - 2] % mod) % mod;
		}
	}
	else {
		n *= -1;
		for (int i = 2; i <= n; ++i) {
			cache[i] = (-cache[i - 1] % mod + cache[i - 2] % mod) % mod;
		}
	}

	if (cache[n] > 0) {
		cout << 1 << endl << cache[n];
	}
	else if (cache[n] < 0) {
		cout << -1 << endl << -cache[n];
	}
	else {
		cout << 0 << endl << 0;
	}
}