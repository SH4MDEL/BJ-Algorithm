#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

struct Node {
    int e, v;

    bool operator<(const Node& rhs) const {
        return v > rhs.v;
    }
};
vector<Node> vertex[1010];
int n, m, s, e;
int dist[1010];
int pre[1010];
vector<int> route;

void Search(int start)
{
    priority_queue<Node> pq;
    dist[start] = 0;
    pq.push({ start, 0 });
    while (!pq.empty()) {
        int current = pq.top().e;
        int cost = pq.top().v;
        pq.pop();

        if (dist[current] != cost) continue;
        for (const auto& v : vertex[current]) {
            int nextDist = v.e;
            int nextCost = v.v;
            if (dist[nextDist] <= cost + nextCost) continue;
            dist[nextDist] = cost + nextCost;
            pq.push({nextDist, cost + nextCost });
            pre[nextDist] = current;
        }
    }
}

int main()
{
    fastip; sws;

    cin >> n >> m;
    fill(dist, dist + n + 1, inf);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        vertex[a].push_back({ b, c });
    }
    cin >> s >> e;
    Search(s);
    int next = e;
    route.push_back(next);
    while (route.back() != s) {
        next = pre[next];
        route.push_back(next);
    }
    cout << dist[e] << endl << route.size() << endl;
    for (auto itr = route.rbegin(); itr != route.rend(); ++itr) {
        cout << *itr << " ";
    }

}