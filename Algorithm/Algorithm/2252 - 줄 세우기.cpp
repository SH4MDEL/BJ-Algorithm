#include <iostream>
#include <vector>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;


int n, m;
int indegree[33000];
vector<int> vertex[33000];

int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int e, v;
		cin >> e >> v;
		++indegree[v];
		vertex[e].push_back(v);
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		int curr = q.front();
		q.pop();

		cout << curr << " ";
		for (const auto& elm : vertex[curr]) {
			--indegree[elm];
			if (indegree[elm] == 0) q.push(elm);
		}
	}
	
}