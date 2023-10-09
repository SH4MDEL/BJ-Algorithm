#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
vector<int> v[55];
bool visited[55];
int score[55];
int maxScore = inf, num;

void bfs(int search)
{
	memset(visited, false, sizeof(bool) * 55);

	int maxDepth = -inf;
	queue<pair<int, int>> q;
	q.push({ search, 0 });
	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		int now = front.first;
		int depth = front.second;

		if (visited[now]) continue;
		visited[now] = true;
		maxDepth = max(maxDepth, depth);

		for (const auto& e : v[now]) {
			q.push({ e, depth + 1 });
		}
	}
	score[search] = maxDepth;
	if (maxDepth < maxScore) {
		num = 0;
		maxScore = maxDepth;
	}
	if (maxDepth == maxScore) {
		++num;
	}
}

int main()
{
	fastip; sws;

	cin >> n;
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;

		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i) {
		bfs(i);
	}
	cout << maxScore << " " << num << endl;
	for (int i = 1; i <= n; ++i) {
		if (score[i] == maxScore) {
			cout << i << " ";
		}
	}
}