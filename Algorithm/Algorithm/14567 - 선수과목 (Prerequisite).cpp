#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int n, m;
int indegree[1010], ans[1010];
vector<int> vertex[1010];

int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		++indegree[b];
		vertex[a].push_back(b);
	}
	queue<int> q;
	
	for (int i = 1; i <= n; ++i) {
		if (!indegree[i]) {
			q.push(i);
			ans[i] = 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		auto curr = q.front(); q.pop();

		for (const auto& e : vertex[curr]) {
			if (!--indegree[e]) {
				ans[e] = max(ans[e], ans[curr] + 1);
				q.push(e);
			}
			else {
				ans[e] = max(ans[e], ans[curr]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
}