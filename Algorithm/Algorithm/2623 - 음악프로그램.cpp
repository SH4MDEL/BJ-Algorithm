#include <iostream>
#include <vector>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;
int indegree[1010];
vector<int> vertex[1010];

int main()
{
	fastip; sws;

	cin >> n >> m;

	int num, v, e;
	for (int i = 0; i < m; ++i) {
		cin >> num;

		cin >> v;
		for (int j = 1; j < num; ++j) {
			cin >> e;
			// 도착점의 수를 늘린다, 즉 indegree가 1 이상이면
			// 이 정점의 줄을 세워서는 안 된다.
			++indegree[e];
			// 출발점과 도착점의 짝을 지어준다.
			vertex[v].push_back(e);
			v = e;
		}
	}

	queue<int> q;
	int ans[1010];

	for (int i = 1; i <= n; ++i) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (q.empty()) {
			// 사이클이 발생했다.
			cout << "0" << endl;
			return 0;
		}

		int curr = q.front();
		q.pop();
		ans[i] = curr;

		for (const auto& elm : vertex[curr]) {
			// curr을 출발점으로 하는 도착지의 indegree를 1 줄인다.
			--indegree[elm];
			// 이렇게 0이 되면 줄을 세워도 된다.
			if (indegree[elm] == 0) q.push(elm);
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << endl;
	}
}