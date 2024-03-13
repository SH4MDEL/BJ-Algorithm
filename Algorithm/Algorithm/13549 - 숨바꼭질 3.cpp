#include <iostream>
#include <queue>
#include <tuple>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, k;
int visited[200200];

void search(int l, int t)
{
	queue<tuple<int, int>> q;
	visited[n] = 0;
	q.push({ l, t });

	while (!q.empty()) {
		auto [now, time] = q.front(); q.pop();
		if (now == k) continue;

		if (now + 1 <= max(n, k) && visited[now + 1] > time + 1) {
			q.push({ now + 1, time + 1 });
			visited[now + 1] = time + 1;
		}
		if (now - 1 >= 0 && visited[now - 1] > time + 1) {
			q.push({ now - 1, time + 1 });
			visited[now - 1] = time + 1;
		}
		if (now * 2 <= max(n, k) * 2 && visited[now * 2] > time) {
			q.push({ now * 2, time });
			visited[now * 2] = time;
		}
	}
}

int main()
{
	fastip; sws;

	fill(visited, visited + 200200, inf);

	cin >> n >> k;
	search(n, 0);
	cout << visited[k];
}