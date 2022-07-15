#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define endl "\n"
#define inf 987'654'321
using namespace std;

int V, E, K;
int u, v, w;

int dist[20010];
vector<pair<int, int>> vertex[20010];

void Search(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int current = pq.top().second;
		pq.pop();

		for (int i = 0; i < vertex[current].size(); ++i) {
			int next = vertex[current].at(i).first;
			int sumcost = vertex[current].at(i).second;

			if (dist[next] > cost + sumcost) {
				dist[next] = cost + sumcost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> V >> E >> K;
	for (int i = 0; i < E; ++i) {
		cin >> u >> v >> w;
		vertex[u].push_back(make_pair(v, w));
	}
	for (int i = 0; i <= V; ++i) {
		dist[i] = inf;
	}
	Search(K);
	for (int i = 1; i <= V; ++i) {
		if (dist[i] == inf) {
			cout << "INF" << endl;
		}
		else {
			cout << dist[i] << endl;
		}
	}
}