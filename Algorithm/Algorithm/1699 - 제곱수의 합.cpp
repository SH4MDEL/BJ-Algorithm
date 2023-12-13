#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int cache[100100];
int num[350];
int n;

int dp(int i)
{
    if (i == 1) return 1;
    if (cache[i] != -1) return cache[i];

    int minimum = inf;
    for (int j = 1; j < 350; ++j) {
        if (num[j] > i) break;
        minimum = min(minimum, dp(i - num[j]) + 1);
    }
    return cache[i] = minimum;
}

int main() {
    fastip; sws;
    memset(cache, -1, sizeof(int) * 100100);
    cin >> n;
    for (int i = 1; i < 350; ++i) {
        num[i] = i * i;
        cache[i * i] = 1;
        if (i * i > n) break;
    }
    cout << dp(n);
}