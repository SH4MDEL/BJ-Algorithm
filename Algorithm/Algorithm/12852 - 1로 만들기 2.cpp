#include <iostream>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int cache[1000010];
int nex[1000010];
int n;

int dp(int num)
{
    if (num == 1) {
        nex[1] = -1;
        return 1;
    }

    if (cache[num] != -1) return cache[num];

    int minAns = inf;
    int minCos = 0;
    if (num % 3 == 0) {
        auto ans = dp(num / 3) + 1;
        if (minAns > ans) {
            minAns = ans;
            minCos = 1;
        }
    }
    if (num % 2 == 0) {
        auto ans = dp(num / 2) + 1;
        if (minAns > ans) {
            minAns = ans;
            minCos = 2;
        }
    }
    auto ans = dp(num - 1) + 1;
    if (minAns > ans) {
        minAns = ans;
        minCos = 3;
    }

    if (minCos == 1) nex[num] = num / 3;
    if (minCos == 2) nex[num] = num / 2;
    if (minCos == 3) nex[num] = num - 1;
    return cache[num] = minAns;
}

int main()
{
    fastip; sws;

    cin >> n;
    memset(cache, -1, sizeof(int) * (n + 1));
    cout << dp(n) - 1 << endl;;
    int now = n;
    while (nex[now] != -1) {
        cout << now << " ";
        now = nex[now];
    }
    cout << 1;
}