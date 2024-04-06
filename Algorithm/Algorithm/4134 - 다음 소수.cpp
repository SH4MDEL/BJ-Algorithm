#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

ll n, t;

bool isPrime(ll num)
{
	if (num == 0 || num == 1) return false;
	for (ll i = 2; i * i <= num; ++i) {
		if (!(num % i)) return false;
	}
	return true;
}

int main()
{
	fastip; sws;

	cin >> t;
	while (t--) {
		cin >> n;
		while (!isPrime(n++)) {}
		cout << n - 1 << endl;
	}
}