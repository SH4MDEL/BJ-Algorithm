#include <iostream>
#include <ranges>
#include <algorithm>
#include <string>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int isPrime[4000400];
int primeNum[2000400];
int n, m;

int main()
{
	fastip; sws;
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= 4000000; ++i) {
		if (isPrime[i]) {
			for (int j = i * i; j <= 4000000; j += i) {
				isPrime[j] = false;
			}
		}
	}
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		if (isPrime[i]) primeNum[m++] = i;
	}
	int s = 0, e = 0, sum = 0, ans = 0;
	while (s <= e && e <= m) {
		if (sum < n) sum += primeNum[e++];
		else sum -= primeNum[s++];
		if (sum == n) ++ans;
	}
	cout << ans;
}