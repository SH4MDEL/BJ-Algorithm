#include <iostream>
#include <queue>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m, ans;
bool visited[505];
vector<int> v[505];
queue<pair<int, int>> q;

void bfs()
{
	q.push({ 1, 0 });
	while (!q.empty()) {
		auto now = q.front(); q.pop();
		auto number = now.first;
		auto depth = now.second;

		if (depth == 3 || visited[number]) continue;
		visited[number] = true;
		++ans;
		for (const auto& e : v[number]) {
			q.push({ e, depth + 1 });
		}
		
	}
}

int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs();
	cout << ans - 1;
}