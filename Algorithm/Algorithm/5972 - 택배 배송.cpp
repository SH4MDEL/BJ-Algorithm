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
vector<Node> vertex[50500];
int dist[50500];
int n, m;

void search(int start)
{
    priority_queue<Node> pq;
    pq.push({ start, 0 });  // 비용 및 경로 삽입
    dist[start] = 0;

    while (!pq.empty()) {
        int current = pq.top().e;
        int cost = pq.top().v;
        pq.pop();

        for (const auto& v : vertex[current]) {
            int nextCost = v.v;
            int nextDist = v.e;
            if (dist[nextDist] > cost + nextCost) {
                dist[nextDist] = cost + nextCost;
                pq.push({ nextDist, cost + nextCost });
            }

        }

    }
}

int main()
{
    fastip; sws;

    cin >> n >> m;
    fill(dist, dist + n + 1, inf);
    for (int i = 0; i < m; ++i) {
        int s, e, v;
        cin >> s >> e >> v;
        vertex[s].push_back({ e, v });
        vertex[e].push_back({ s, v });
    }
    search(1);
    cout << dist[n];
}