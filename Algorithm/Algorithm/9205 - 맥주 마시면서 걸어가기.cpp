#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int t, n;
pair<int, int> s, e;
vector<pair<pair<int, int>, bool>> m;
bool visited[110];

bool dist(pair<int, int> st, pair<int, int> ed)
{
	return (abs(st.first - ed.first) + abs(st.second - ed.second)) <= 1000;
}

bool bfs(int sx, int sy)
{
	queue<pair<int, int>> q;
	if (dist(s, e)) return true;
	for (int i = 0; i < m.size(); ++i) {
		if (dist(s, m[i].first)) {
			m[i].second = true;
			q.push(m[i].first);
		}
	}
	while (!q.empty()) {
		auto now = q.front(); q.pop();
		if (dist(now, e)) return true;
		for (int i = 0; i < m.size(); ++i) {
			if (m[i].second) continue;
			if (dist(now, m[i].first)) {
				m[i].second = true;
				q.push(m[i].first);
			}
		}
	}
	return false;
}

int main()
{
	fastip; sws;

	cin >> t;
	while (t--) {
		memset(visited, false, sizeof visited);
		m.clear();
		cin >> n;
		cin >> s.first >> s.second;
		m.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> m[i].first.first >> m[i].first.second;
			m[i].second = false;
		}
		cin >> e.first >> e.second;
		if (bfs(s.first, s.second)) cout << "happy" << endl;
		else cout << "sad" << endl;
	}
}