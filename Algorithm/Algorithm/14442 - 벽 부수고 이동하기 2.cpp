#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

const array<int, 4> dx = { 1, 0, -1, 0 };
const array<int, 4> dy = { 0, 1, 0, -1 };
struct Node {
    int y, x, wall, depth;
};
queue<Node> q;
int n, m, k;
bool visited[11][1010][1010];
bool map[1010][1010];

int bfs()
{
    q.push({ 1, 1, 0, 1 });
    visited[0][1][1] = true;
    while (!q.empty()) {
        auto now = q.front(); q.pop();
        if (now.y == n && now.x == m) return now.depth;

        for (int i = 0; i < 4; ++i) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (now.wall != k) {
                bool search = true;
                for (int j = 0; j < now.wall + 1; ++j) {
                    if (visited[j][ny][nx]) {
                        search = false;
                        break;
                    }
                }
                if (!search) continue;
                if (!visited[now.wall + 1][ny][nx] &&
                    ny > 0 && nx > 0 && ny <= n && nx <= m) {
                    visited[now.wall + 1][ny][nx] = true;
                    q.push({ ny, nx, now.wall + 1, now.depth + 1 });
                }
            }

            if (!visited[now.wall][ny][nx] && !map[ny][nx] &&
                ny > 0 && nx > 0 && ny <= n && nx <= m) {
                visited[now.wall][ny][nx] = true;
                q.push({ ny, nx, now.wall, now.depth + 1 });
            }
        }
    }
    return -1;
}

int main() {
    fastip; sws;

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            map[i][j] = c - '0';
        }
    }
    cout << bfs();
}