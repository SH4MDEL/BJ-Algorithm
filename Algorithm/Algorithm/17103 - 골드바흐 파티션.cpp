#include <iostream>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int t, n;
bool isPrime[1000100];

int main()
{
	fastip; sws;

	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= 1000000; ++i) {
		if (isPrime[i]) {
			for (int j = i * i; j <= 1000000; j += i) {
				isPrime[j] = false;
			}
		}
	}

	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0;
		for (int i = 2; i <= n / 2; ++i) {
			if (isPrime[i] && isPrime[n - i]) ++ans;
		}
		cout << ans << endl;
	}
}