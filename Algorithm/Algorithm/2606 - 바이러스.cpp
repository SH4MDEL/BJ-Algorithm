#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#define inf 987654321 
#define endl "\n"
using namespace std;

bool map[101][101];
bool visited[101];
bool infested[101];
int n, m;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);
	memset(map, false, sizeof(bool) * 101 * 101);
	memset(visited, false, sizeof(bool) * 101);
	memset(infested, false, sizeof(bool) * 101);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		map[a][b] = true;
		map[b][a] = true;
	}

	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int current = q.front(); q.pop();
		if (visited[current]) continue;
		visited[current] = true;
		infested[current] = true;
		for (int i = 1; i <= n; ++i) {
			if (map[current][i]) {
				q.push(i);
			}
		}
	}
	int counting = 0;
	for (int i = 1; i <= n; ++i) {
		if (infested[i]) {
			++counting;
		}
	}
	cout << counting - 1;
}