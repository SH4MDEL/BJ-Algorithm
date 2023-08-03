#include <iostream>
#include <cmath>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
int cache[1010][3];
int cost[1010][3];

int dp(int depth, int house)
{
    if (depth == n) return 0;

    if (cache[depth][house] != -1) return cache[depth][house];
    if (house == 0) {
        return cache[depth][house] = min(dp(depth + 1, 1) + cost[depth][house], dp(depth + 1, 2) + cost[depth][house]);
    }
    if (house == 1) {
        return cache[depth][house] = min(dp(depth + 1, 0) + cost[depth][house], dp(depth + 1, 2) + cost[depth][house]);
    }
    if (house == 2) {
        return cache[depth][house] = min(dp(depth + 1, 0) + cost[depth][house], dp(depth + 1, 1) + cost[depth][house]);
    }
}

int main()
{
    sws; fastip;

    cin >> n;
    memset(cache, -1, 3030);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> cost[i][j];
        }
    }
    int minNum = inf;
    minNum = min(dp(0, 0), minNum);
    minNum = min(dp(0, 1), minNum);
    minNum = min(dp(0, 2), minNum);
    cout << minNum << endl;
}