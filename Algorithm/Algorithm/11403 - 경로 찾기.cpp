#include <iostream>
#include <queue>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
vector<int> v[105];
queue<int> q;
bool visited[105][105];

void bfs(int search)
{
	for (const auto& e : v[search]) {
		q.push(e);
	}
	while (!q.empty()) {
		auto now = q.front(); q.pop();
		if (visited[search][now]) continue;
		visited[search][now] = true;
		for (const auto& e : v[now]) {
			q.push(e);
		}
	}
}

int main()
{
	fastip; sws;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			bool map;
			cin >> map;
			if (map) v[i].push_back(j);
		}
	}
	for (int i = 0; i < n; ++i) {
		bfs(i);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}