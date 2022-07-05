#include <iostream>
#include <queue>
#define endl "\n"
#define inf 987654321
using namespace std;

int visited[200020];
int n, k;
int kcount = 0;

queue<int> q;

void bfs(int x)
{
	q.push(x);
	visited[x] = 0;

	[&]() {
		while (!q.empty()) {
			auto qsize = q.size();
			for (int i = 0; i < qsize; ++i) {
				int current = q.front();
				q.pop();

				if (current + 1 == k) {
					++kcount;
				}
				if (current - 1 == k) {
					++kcount;
				}
				if (current * 2 == k) {
					++kcount;
				}
				if (visited[current + 1] == -1 && current + 1 <= 100000) {
					q.push(current + 1);
					visited[current + 1] = visited[current] + 1;
				}
				if (visited[current - 1] == -1 && current - 1 >= 0) {
					q.push(current - 1);
					visited[current - 1] = visited[current] + 1;
				}
				if (current * 2 <= 100000 && visited[current * 2] == -1) {
					q.push(current * 2);
					visited[current * 2] = visited[current] + 1;
				}
			}
			if (visited[k] != -1) {
				return;
			}
		}
	}();
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < 200020; ++i) {
		visited[i] = -1;
	}
	bfs(n);
	cout << visited[k] << endl << kcount << endl;
}