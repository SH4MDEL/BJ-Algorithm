#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
#define inf 987'654'321
using namespace std;

int n, m, x;
int s, e, t;
vector<pair<int, int>> vertex[1005];
int dist[1005];
int distsum[1005];

void Dijkstra(int start, bool isReturn)
{
	for (int i = 0; i < 1005; ++i) {
		dist[i] = inf;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cost = pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (dist[current] < cost) continue;

		for (int i = 0; i < vertex[current].size(); ++i) {
			int curcost = vertex[current][i].first;
			int next = vertex[current][i].second;

			if (dist[next] > cost + curcost) {
				dist[next] = cost + curcost;
				pq.push(make_pair(dist[next], next));
			}

			//if (next == x && isReturn) {
			//	return;
			//}
		}
	}
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n >> m >> x;

	for (int i = 0; i < m; ++i) {
		cin >> s >> e >> t;
		vertex[s].push_back(make_pair(t, e));
	}
	Djikstra(x, false);
	for (int i = 1; i <= n; ++i) {
		distsum[i] += dist[i];
	}
	int maxdist = -1;
	for (int i = 1; i <= n; ++i) {
		Djikstra(i, true);
		distsum[i] += dist[x];
		if (maxdist < distsum[i]) {
			maxdist = distsum[i];
		}
	}
	cout << maxdist << endl;
}