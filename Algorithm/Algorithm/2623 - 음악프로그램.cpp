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
			// �������� ���� �ø���, �� indegree�� 1 �̻��̸�
			// �� ������ ���� �������� �� �ȴ�.
			++indegree[e];
			// ������� �������� ¦�� �����ش�.
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
			// ����Ŭ�� �߻��ߴ�.
			cout << "0" << endl;
			return 0;
		}

		int curr = q.front();
		q.pop();
		ans[i] = curr;

		for (const auto& elm : vertex[curr]) {
			// curr�� ��������� �ϴ� �������� indegree�� 1 ���δ�.
			--indegree[elm];
			// �̷��� 0�� �Ǹ� ���� ������ �ȴ�.
			if (indegree[elm] == 0) q.push(elm);
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << endl;
	}
}