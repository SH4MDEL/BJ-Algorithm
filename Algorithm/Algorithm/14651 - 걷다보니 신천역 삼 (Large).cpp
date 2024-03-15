#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
#define mod 1'000'000'009
using namespace std;

int n;

int main()
{
	fastip; sws;

	cin >> n;
	if (n == 1) cout << 0;
	else {
		int ans = 2;
		for (int i = 2; i < n; ++i) {
			ans = ((ans % mod) * (3 % mod)) % mod;
		}
		cout << ans;
	}
}