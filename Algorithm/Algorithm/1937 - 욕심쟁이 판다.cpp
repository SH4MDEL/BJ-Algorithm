#include <iostream>
#include <array>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int cache[510][510];
int map[510][510];
int n;

constexpr array<int, 4> dx = { -1, 1, 0, 0 };
constexpr array<int, 4> dy = { 0, 0, -1, 1 };

int dfs(int y, int x)
{
    if (cache[y][x] != -1) return cache[y][x];

    int maximum = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (map[ny][nx] > map[y][x]) {
            maximum = max(maximum, dfs(ny, nx) + 1);
        }
    }
    return cache[y][x] = maximum;
}

int main()
{
    sws; fastip;

    memset(cache, -1, sizeof(int) * 510 * 510);
    memset(map, inf, sizeof(int) * 510 * 510);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> map[i][j];
        }
    }
    int maximum = -inf;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            maximum = max(maximum, dfs(i, j));
        }
    }
    cout << maximum + 1;
}