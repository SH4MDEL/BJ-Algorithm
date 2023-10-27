#include <iostream>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int map[1010][1010];
int cache[1010][1010];
int n, m;

int dp(int x, int y)
{
    if (x > m || y > n || x <= 0 || y <= 0) return 0;
    if (x == m and y == n) return cache[y][x] = map[y][x];

    if (cache[y][x] != -1) return cache[y][x];

    return cache[y][x] = max({ dp(x + 1, y), dp(x, y + 1), dp(x + 1, y + 1) }) + map[y][x];
}

int main() 
{
    fastip; sws;

    cin >> n >> m;
    memset(cache, -1, sizeof(int) * 1010 * 1010);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> map[i][j];
        }
    }
    cout << dp(1, 1);
}