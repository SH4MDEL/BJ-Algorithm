#include <iostream>
#include <queue>
#define endl "\n"
#define inf 987654321
using namespace std;

int n, m;
int num, counter;
bool visited[101010] = {false};

void bfs()
{
	queue<pair<int, int>> q;
	q.push({ n, 0 });

	while (!q.empty()) {
		int now = q.front().first;
		int time = q.front().second;
		q.pop();

		visited[now] = true;
		if (time > num) continue;

		if (now == m) {
			if (num > time) {
				num = time;
				counter = 1;
				continue;
			}
			num = time;
			++counter;
			continue;
		}
		if (now * 2 <= 100000 && !visited[now * 2]) q.push({ now * 2, time + 1 });
		if (now + 1 <= 100000 && !visited[now + 1]) q.push({ now + 1, time + 1 });
		if (now - 1 >= 0 && !visited[now - 1]) q.push({ now - 1, time + 1 });
	}
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	num = inf;
	cin >> n >> m;
	bfs();
	cout << num << endl << counter << endl;
}