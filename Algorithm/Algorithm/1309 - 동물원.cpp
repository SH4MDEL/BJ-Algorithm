#include <iostream>
#include <string>
#include <tuple>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define mod 9901
#define ll long long
#define endl "\n"
using namespace std;

int n;
int cache[100100][3];

int main()
{
	fastip; sws;

	cin >> n;
	cache[0][0] = cache[0][1] = cache[0][2] = 1;
	for (int i = 1; i <= n; ++i) {
		cache[i][0] = (
			cache[i - 1][0] % mod + 
			cache[i - 1][1] % mod + 
			cache[i - 1][2] % mod) % mod;
		cache[i][1] = (
			cache[i - 1][0] % mod +
			cache[i - 1][2] % mod) % mod;
		cache[i][2] = (
			cache[i - 1][0] % mod +
			cache[i - 1][1] % mod) % mod;
	}
	cout << cache[n][0];
}