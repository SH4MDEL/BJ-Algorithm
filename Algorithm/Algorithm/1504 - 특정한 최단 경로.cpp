#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
#define inf 687'654'321
using namespace std;

int n, e;
int a, b, c;
int v1, v2;

vector<pair<int, int>> vertex[805];
int dist[805];

void Search(int start)
{
	for (int i = 0; i < 805; ++i) {
		dist[i] = inf;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cost = pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (cost > dist[current]) continue;

		for (int i = 0; i < vertex[current].size(); ++i) {
			int curcost = vertex[current].at(i).first;
			int next = vertex[current].at(i).second;

			if (dist[next] > cost + curcost) {
				dist[next] = cost + curcost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n >> e;
	for (int i = 0; i < e; ++i) {
		cin >> a >> b >> c;
		vertex[a].push_back(make_pair(c, b));
		vertex[b].push_back(make_pair(c, a));
	}
	cin >> v1 >> v2;
	Search(1);
	int StartToV1 = dist[v1], StartToV2 = dist[v2];
	Search(v1);
	int V1ToEnd = dist[n], V1ToV2 = dist[v2];
	Search(v2);
	int V2ToEnd = dist[n], V2ToV1 = dist[v1];

	int answer = min(StartToV1 + V1ToV2 + V2ToEnd, StartToV2 + V2ToV1 + V1ToEnd);

	if (answer >= inf) {
		cout << "-1" << endl;
	}
	else {
		cout << answer << endl;
	}
}