#include <iostream>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, limit;
int weight[110];
int value[110];
int cache[110][110000];

int dp(int depth, int leastWeight)
{
    if (depth == n) return 0;

    if (cache[depth][leastWeight] != -1) return cache[depth][leastWeight];

    if (leastWeight - weight[depth] < 0) return cache[depth][leastWeight] = dp(depth + 1, leastWeight);

    return cache[depth][leastWeight] = max(dp(depth + 1, leastWeight), 
        dp(depth + 1, leastWeight - weight[depth]) + value[depth]);
}

int main()
{
    sws; fastip;

    cin >> n >> limit;

    memset(cache, -1, sizeof(int) * 110 * 110000);

    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }

    cout << dp(0, limit);
}