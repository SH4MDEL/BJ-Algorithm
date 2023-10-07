#include <iostream>
#include <queue>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

vector<int> node[1010];
bool visited[1010];
int n, m, ans;
queue<pair<int, int>> q;

void dfs(int s)
{
	visited[s] = true;
	for (const auto& e : node[s]) {
		if (visited[e]) continue;
		dfs(e);
	}
}

int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		if (visited[i]) continue;
		dfs(i);
		++ans;
	}
	cout << ans;
}