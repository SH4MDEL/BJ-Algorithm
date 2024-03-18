#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m, s, d;

struct Edge {
	int to, value;

	bool operator<(const Edge& rhs) const {
		return value > rhs.value;
	}
};
vector<Edge> edges[550];
int dist[550];
bool deleted[550][550];
vector<int> pred[550];
bool visited[550];

// Ʋ�� ������ ũ�� �� ����
// 1. ���� ������ �湮üũ X
//	- �޸��ʰ���
// 2. dist[next] == cost�� ��쿡�� pq�� push
//	- �޸��ʰ���
// 3. ù ���� ���� �� dist �ʱ�ȭ X
//	- ù ��ο��� �ٷ� �ִܰ�� ���� �� ��� ������ �ȵ�

void deleteNode(int index)
{
	if (index == s || visited[index]) return;
	visited[index] = true;
	for (const auto& elm : pred[index]) {
		deleted[elm][index] = true;
		deleteNode(elm);
	}
}

void bfs()
{
	priority_queue<Edge> pq;

	for (const auto& edge : edges[s]) {
		pq.push({ edge.to, edge.value });
		dist[edge.to] = edge.value;
		pred[edge.to].push_back(s);
	}
	dist[s] = 0;

	while (!pq.empty()) {
		auto now = pq.top(); pq.pop();
		if (now.to == d) {
			deleteNode(d);
			return;
		}

		for (const auto& edge : edges[now.to]) {
			int next = edge.to;
			int cost = now.value + edge.value;

			if (dist[next] > cost) {
				dist[next] = cost;
				pq.push({ next, cost });
				pred[next].clear();
				pred[next].push_back(now.to);
			}
			else if (dist[next] == cost) {
				pred[next].push_back(now.to);
			}
		}
	}
}

int dijk()
{
	priority_queue<Edge> pq;

	for (const auto& edge : edges[s]) {
		if (!deleted[s][edge.to]) pq.push(edge);
	}
	dist[s] = 0;

	while (!pq.empty()) {
		auto now = pq.top(); pq.pop();
		if (now.to == d) {
			return now.value;
		}

		for (const auto& edge : edges[now.to]) {
			if (deleted[now.to][edge.to]) continue;
			int next = edge.to;
			int cost = now.value + edge.value;

			if (dist[next] > cost) {
				dist[next] = cost;
				pq.push({ next, cost });
			}
		}

	}
	return -1;
}

int main()
{
	fastip; sws;

	cin >> n >> m;
	while (n && m) {
		cin >> s >> d;

		memset(deleted, false, sizeof(deleted));
		memset(visited, false, sizeof(visited));
		memset(dist, 0x7f, sizeof(dist));
		for (int i = 0; i < 550; ++i) {
			edges[i].clear();
		}
		for (int i = 0; i < 550; ++i) {
			pred[i].clear();
		}

		for (int i = 0; i < m; ++i) {
			int u, v, p;
			cin >> u >> v >> p;
			edges[u].push_back(Edge{ v, p });
		}

		bfs();

		memset(dist, 0x7f, sizeof(dist));

		cout << dijk() << endl;

		cin >> n >> m;
	}
}