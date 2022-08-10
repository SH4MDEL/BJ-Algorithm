#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
#define inf 10'987'654'321
using namespace std;

int n, m, k, V, E, K;

vector<pair<int, int>> vertex[10101];
long long dist[10101][22];

void Dijkstra()
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			dist[i][j] = inf;
		}
	}
	priority_queue<pair<pair<long long, int>, int>> pq;
	dist[0][k] = 0;
	pq.push({{0, 0}, k});

	while (!pq.empty()) {
		long long cost = -pq.top().first.first;
		int current = pq.top().first.second;
		int update = pq.top().second;
		pq.pop();

		if (cost > dist[current][update]) continue;

		for (int i = 0; i < vertex[current].size(); ++i) {
			long long curcost = vertex[current].at(i).first;
			int next = vertex[current].at(i).second;

			if (dist[next][update] > cost + curcost) {
				dist[next][update] = cost + curcost;
				pq.push({ {-dist[next][update], next}, update });
			}
			if (update > 0 && dist[next][update - 1] > cost) {
				dist[next][update - 1] = cost;
				pq.push({ {-dist[next][update - 1], next}, update - 1 });
			}
		}
	}
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i) {
		cin >> V >> E >> K;
		vertex[V - 1].push_back({ K, E - 1 });
		vertex[E - 1].push_back({ K, V - 1 });
	}
	Dijkstra();
	long long minimum = inf;
	for (int i = 0; i <= k; ++i) {
		if (dist[n - 1][i] < minimum) {
			minimum = dist[n - 1][i];
		}
	}
	cout << minimum << endl;
}