#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
#define inf 987'654'321
using namespace std;

vector<pair<int, int>> vertex[1005];
int dist[1005];

int n, m;
int a, b, c;
int s, e;

void Search(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int current = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		for (int i = 0; i < vertex[current].size(); ++i) {
			int sumcost = vertex[current].at(i).first;
			int next = vertex[current].at(i).second;

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

	cin >> n >> m;
	for (int i = 0; i <= n; ++i) {
		dist[i] = inf;
	}
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		vertex[a].push_back(make_pair(c, b));
	}
	cin >> s >> e;
	Search(s);
	cout << dist[e] << endl;
}