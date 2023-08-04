#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <vector>
#define inf 987654321 
#define endl "\n"
using namespace std;

vector<int> v[101000];
bool visited[101000];
int parent[101000];
int n;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);
	memset(visited, false, sizeof(bool) * 101000);
	memset(parent, -1, sizeof(int) * 101000);

	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int current = q.front(); q.pop();
		if (visited[current]) continue;
		visited[current] = true;
		for (const auto& c : v[current]) {
			if (parent[c] == -1) {
				parent[c] = current;
				q.push(c);
			}
		}
	}
	for (int i = 2; i <= n; ++i) {
		cout << parent[i] << endl;
	}
}