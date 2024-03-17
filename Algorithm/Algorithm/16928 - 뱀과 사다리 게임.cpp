#include <iostream>
#include <unordered_map>
#include <optional>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;
unordered_map<int, int> um;
vector visited(101, optional<bool>());

int bfs()
{
	queue<tuple<int, int>> q;
	q.push({ 1, 1 });
	while (!q.empty()) {
		auto [now, depth] = q.front(); q.pop();

		for (int i = 1; i <= 6; ++i) {
			if (now + i > 100) break;
			int next = now + i;
			if (next == 100) return depth;

			if (um.count(next)) next = um[next];
			if (visited[next].has_value()) continue;

			q.push({ next, depth + 1 });
			visited[next].emplace(true);
		}
	}
	return 0;
}

int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 0; i < n + m; ++i) {
		int a, b;
		cin >> a >> b;
		um[a] = b;
	}
	cout << bfs();
}