#include <iostream>
#include <unordered_set>
#include <tuple>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int t, s, e;
bool visited[10101];

string bfs()
{
	queue<tuple<int, string>> q;
	q.push({ s, "" });
	while (!q.empty()) {
		auto [now, command] = q.front(); q.pop();

		auto D = (now * 2) % 10000;
		if (D == e) return command + "D";
		if (!visited[D]) {
			visited[D] = true;
			q.push({ D, command + "D" });
		}
		auto S = ((now != 0) ? now - 1 : 9999);
		if (S == e) return command + "S";
		if (!visited[S]) {
			visited[S] = true;
			q.push({ S, command + "S" });
		}
		auto L = (now % 1000) * 10 + (now / 1000);
		if (L == e) return command + "L";
		if (!visited[L]) {
			visited[L] = true;
			q.push({ L, command + "L" });
		}
		auto R = (now % 10) * 1000 + (now / 10);
		if (R == e) return command + "R";
		if (!visited[R]) {
			visited[R] = true;
			q.push({ R, command + "R" });
		}
	}
	return "";
}

int main()
{
	fastip; sws;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		fill(visited, visited + 10101, false);
		cin >> s >> e;
		cout << bfs() << endl;
	}
}