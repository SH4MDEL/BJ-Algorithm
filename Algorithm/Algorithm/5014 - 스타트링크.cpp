#include <iostream>
#include <queue>
#define endl "\n"
#define inf 987654321
using namespace std;

int visited[1000001];
int f, s, g, u, d;

queue<int> q;

void bfs(int x)
{
	q.push(x);
	visited[x] = 0;

	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; ++i) {
			int current = q.front();
			q.pop();

			if (current + u <= f) {
				if (visited[current + u] == -1) {
					visited[current + u] = visited[current] + 1;
					q.push(current + u);
				}
			}
			if (current - d >= 1) {
				if (visited[current - d] == -1) {
					visited[current - d] = visited[current] + 1;
					q.push(current - d);
				}
			}

			if (visited[g] != -1) {
				return;
			}
		}
	}
}

int main()
{
	cin >> f >> s >> g >> u >> d;
	for (int i = 0; i <= 1000000; ++i) {
		visited[i] = -1;
	}
	bfs(s);
	if (visited[g] == -1) {
		cout << "use the stairs" << endl;
	}
	else {
		cout << visited[g] << endl;
	}
}