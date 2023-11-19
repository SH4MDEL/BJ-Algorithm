#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
int cost[550];
int root[550];
vector<int> vertex[550];
int ans[550];

int main()
{
	fastip; sws;
	queue<int> q;

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> cost[i];
		int a = 0;
		while (1) {
			cin >> a;
			if (a == -1) break;
			vertex[a].push_back(i);
			++root[i];
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (root[i] == 0) q.push(i);
	}

	for (int i = 1; i <= n; ++i) {
		int now = q.front(); q.pop();

		ans[now] += cost[now];
		for (const auto& e : vertex[now]) {
			ans[e] = max(ans[e], ans[now]);
			--root[e];
			if (root[e] == 0) q.push(e);
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << endl;
	}
}