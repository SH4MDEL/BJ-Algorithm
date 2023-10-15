#include <iostream>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

#define mod 1'000'000'009

long long cache[1010101];
long long n;

int main()
{
    fastip; sws;
    memset(cache, -1, sizeof(int) * 1010101);
    cache[1] = 1; cache[2] = 2; cache[3] = 4; cache[4] = 7;
    cin >> n;
    for (int i = 5; i < 1000001; ++i) {
        cache[i] = (cache[i - 3] + cache[i - 2] + cache[i - 1]) % mod;
    }
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        cout << cache[k] << endl;
    }
}