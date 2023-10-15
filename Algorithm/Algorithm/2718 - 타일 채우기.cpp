#include <iostream>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

#define mod 1'000'000'009

int t, n;
int cache[101010][14];
// 0 : 0
// 1 : 1
// 2 : 2
// 3 : 3
// 4 : 4
// 5 : 1 2
// 6 : 1 3
// 7 : 1 4
// 8 : 2 3
// 9 : 2 4
// 10 : 3 4
// 11 : 123
// 12 : 124
// 13 : 234
// 14 : 134

int dp(int k, int type)
{
    if (k == 0 || k == 0) {
        if (type == 0) {
            return 1;
        }
        return 0;
    }
    if (cache[k][type] != -1) return cache[k][type];

    if (type == 0) {
        return cache[k][type] =
            dp(k - 1, 0) + dp(k - 1, 5) + dp(k - 1, 7) + dp(k - 1, 10) + dp(k - 2, 0);
    }
    else if (type == 1) {
        return cache[k][type] = dp(k - 1, 13) + dp(k - 1, 4) + dp(k - 1, 2);
    }
    else if (type == 2) {
        return cache[k][type] = dp(k - 1, 1) + dp(k - 1, 14);
    }
    else if (type == 3) {
        return cache[k][type] = dp(k - 1, 4) + dp(k - 1, 12);
    }
    else if (type == 4) {
        return cache[k][type] = dp(k - 1, 1) + dp(k - 1, 3) + dp(k - 1, 11);
    }
    else if (type == 5) {
        return cache[k][type] = dp(k - 1, 0) + dp(k - 1, 10);
    }
    else if (type == 6) {
        return cache[k][type] = dp(k - 1, 9);
    }
    else if (type == 7) {
        return cache[k][type] = dp(k - 1, 0) + dp(k - 1, 8);
    }
    else if (type == 8) {
        return cache[k][type] = dp(k - 1, 7);
    }
    else if (type == 9) {
        return cache[k][type] = dp(k - 1, 6);
    }
    else if (type == 10) {
        return cache[k][type] = dp(k - 1, 0) + dp(k - 1, 5);
    }
    else if (type == 11) {
        return cache[k][type] = dp(k - 1, 4);
    }
    else if (type == 12) {
        return cache[k][type] = dp(k - 1, 3);
    }
    else if (type == 13) {
        return cache[k][type] = dp(k - 1, 1);
    }
    else // (type == 14) 
    {
        return cache[k][type] = dp(k - 1, 2);
    }
}

int main()
{
    fastip; sws;
    memset(cache, -1, sizeof(int) * 101010 * 14);

    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        cout << dp(n, 0) << endl;
    }
}