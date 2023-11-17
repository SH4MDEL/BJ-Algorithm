#include <iostream>
#include <queue>
#include <array>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int n, m;
int map[10][10];
int test[10][10];
bool visited[10][10];
int ans = -1;

const array<int, 4> dx = { -1, 1, 0, 0 };
const array<int, 4> dy = { 0, 0, -1, 1 };

void bfs(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({ y, x });
    visited[y][x] = true;
    while (!q.empty()) {
        auto now = q.front(); q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];

            if (!visited[ny][nx] && ny <= n && ny > 0 && nx <= m && nx > 0 &&
                test[ny][nx] == 0) {
                q.push({ ny, nx });
                test[ny][nx] = 2;
                visited[ny][nx] = true;
            }
        }
    }
}

int main() {
    fastip; sws;

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i <= n * m - 2; ++i) {
        for (int j = i + 1; j <= n * m - 1; ++j) {
            for (int k = j + 1; k <= n * m; ++k) {
                int y1 = i / m + 1, x1 = i % m + 1;
                int y2 = j / m + 1, x2 = j % m + 1;
                int y3 = k / m + 1, x3 = k % m + 1;
                //std::cout << y1 << ", " << x1 << ", " << y2 << ", " << x2 << ", " << y3 << ", " << x3 << endl;
                if (x1 > 0 && x1 <= m && x2 > 0 && x2 <= m && x3 > 0 && x3 <= m &&
                    y1 > 0 && y1 <= n && y2 > 0 && y2 <= n && y3 > 0 && y3 <= n &&
                    map[y1][x1] == 0 && map[y2][x2] == 0 && map[y3][x3] == 0) {
                    for (int i = 1; i <= n; ++i) {
                        for (int j = 1; j <= m; ++j) {
                            test[i][j] = map[i][j];
                        }
                    }
                    test[y1][x1] = 1;
                    test[y2][x2] = 1;
                    test[y3][x3] = 1;
                    for (int i = 1; i <= n; ++i) {
                        for (int j = 1; j <= m; ++j) {
                            visited[i][j] = false;
                        }
                    }
                    for (int i = 1; i <= n; ++i) {
                        for (int j = 1; j <= m; ++j) {
                            if (test[i][j] == 2 && !visited[i][j]) {
                                bfs(i, j);
                            }
                        }
                    }
                    int count = 0;
                    for (int i = 1; i <= n; ++i) {
                        for (int j = 1; j <= m; ++j) {
                            if (test[i][j] == 0) {
                                ++count;
                            }
                        }
                    }
                    ans = max(ans, count);
                }
            }
        }
    }
    std::cout << ans;
}