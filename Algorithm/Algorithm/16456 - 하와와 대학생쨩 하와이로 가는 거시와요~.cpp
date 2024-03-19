#include <iostream>
#include <string>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'009
using namespace std;

int n;
int cache[4][50500];

int main()
{
	fastip; sws;

	cin >> n;
	cache[0][0] = 1; cache[1][0] = 0; cache[2][0] = 1, cache[3][0] = 1;
	for (int i = 1; i < n; ++i) {
		cache[0][i] = ((cache[0][i - 1] % mod) + (cache[1][i - 1] % mod)) % mod;
		cache[1][i] = cache[3][i - 1] % mod;
		cache[2][i] = ((cache[0][i - 1] % mod) + (cache[1][i - 1] % mod)) % mod;
		cache[3][i] = cache[2][i - 1] % mod;
	}
	cout << cache[0][n - 1];
}

//#include <iostream>
//using namespace std;
//
//int n;
//int cache[50005];
//
//int main()
//{
//	cin >> n;
//	cache[0] = cache[1] = cache[2] = 1;
//	for (int i = 3; i <= n; ++i) {
//		cache[i] = (cache[i - 1] + cache[i - 3]) % 1000000009;
//	}
//	cout << cache[n];
//}