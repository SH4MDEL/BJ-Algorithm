#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 10007
using namespace std;

// 이항 계수 성질
// nCr = n-1Cr-1 + n-1Cr

int N, K;
int cache[1010][1010];

int dp(int n, int k)
{
    if (k == 0 || n == k) return 1;
    if (cache[n][k] != -1) return cache[n][k];

    return cache[n][k] = (dp(n - 1, k - 1) % mod + dp(n - 1, k) % mod) % mod;
}

int main() {
    fastip; sws;

    memset(cache, -1, sizeof(int) * 1010 * 1010);
    cin >> N >> K;
    cout << dp(N, K);
}