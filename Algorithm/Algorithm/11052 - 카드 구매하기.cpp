#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
int card[1010];
int cache[1010];

int dp(int i)
{
    if (cache[i] != -1) return cache[i];

    int maximum = -1;
    for (int j = 1; j <= i; ++j) {
        maximum = max(maximum, card[j] + dp(i - j));
    }
    return cache[i] = maximum;
}

int main() {
    fastip; sws;

    memset(cache, -1, sizeof(int) * 1010);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> card[i];
    }
    cache[0] = 0;
    cache[1] = card[1];
    cout << dp(n);
}