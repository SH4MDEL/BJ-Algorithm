#include <iostream>
#include <queue>
#include <stack>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

bool map[1010][1010];
bool visited[1010];
int n, m, v;
stack<int> s;

void dfs()
{
    int current = s.top(); s.pop();
    if (visited[current]) return;
    visited[current] = true;
    cout << current << " ";

    for (int i = 1; i <= n; ++i) {
        if (map[current][i]) {
            s.push(i);
            dfs();
        }
    }
}

void bfs()
{
    queue<int> q;
    q.push(v);

    while (!q.empty()) {
        int current = q.front(); q.pop();

        if (visited[current]) continue;
        visited[current] = true;
        cout << current << " ";

        for (int i = 1; i <= n; ++i) {
            if (map[current][i]) {
                q.push(i);
            }
        }
    }
}

int main()
{
    sws; fastip;

    cin >> n >> m >> v;
    memset(map, false, sizeof(bool) * 1010 * 1010);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        map[a][b] = true;
        map[b][a] = true;
    }

    memset(visited, false, sizeof(bool) * 1010);
    s.push(v);
    dfs();

    cout << endl;
    memset(visited, false, sizeof(bool) * 1010);
    bfs();
}