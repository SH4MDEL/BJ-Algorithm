#include <iostream>
#include <bitset>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

bool visited[1 << 11];
string str;
int s, e;

int bfs()
{
	visited[s] = true;
	queue<pair<int, int>> q;
	q.push({s, 0});
	while (!q.empty()) {
		auto [now, counter] = q.front();
		q.pop();

		if (now == e) return counter;

		if (!visited[now + 1]) {
			visited[now + 1] = true;
			q.push({ now + 1, counter + 1 });
		}
		if (now && !visited[now - 1]) {
			visited[now - 1] = true;
			q.push({ now - 1, counter + 1 });
		}

		bool first = false;
		for (int i = 10; i >= 0; --i) {
			int digit = (1 << i);
			if (first) {
				int next = now ^ (1 << i);
				if (!visited[next]) {
					visited[next] = true;
					q.push({ next, counter + 1 });
				}
			}
			if (now & digit) first = true;
		}
	}
	return inf;
}

int main()
{
	fastip; sws;
	cin >> str;
	int now = 1;
	for (int i = str.length() - 1; i >= 0; --i) {
		if (str[i] == '1') s += now;
		now *= 2;
	}
	cin >> str;
	now = 1;
	for (int i = str.length() - 1; i >= 0; --i) {
		if (str[i] == '1') e += now;
		now *= 2;
	}
	cout << bfs();
}