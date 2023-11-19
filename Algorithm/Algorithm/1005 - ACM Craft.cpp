#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int t, n, k, w;
int cost[1010];
int root[1010];
int ans[1010];
vector<int> vertex[1010];

int main()
{
	fastip; sws;

	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) {
			cin >> cost[i];
		}
		for (int i = 1; i <= n; ++i) {
			vertex[i].clear();
		}
		for (int i = 1; i <= n; ++i) {
			ans[i] = 0;
		}
		for (int i = 0; i < k; ++i) {
			int a, b;
			cin >> a >> b;
			// b�� ���ϴ� ���� �ϳ� �þ���.
			++root[b];
			vertex[a].push_back(b);
		}
		cin >> w;

		queue<int> q;
		for (int i = 1; i <= n; ++i) {
			if (root[i] == 0) q.push(i);
		}
		for (int i = 1; i <= n; ++i) {
			int now = q.front(); q.pop();
			// ���� ���� �� �ִ� �ǹ���
			ans[now] += cost[now];
			// �� �ǹ��� ���� ���� ���� ����.
			for (const auto& e : vertex[now]) {
				--root[e];
				// �ּ� now�� ����� e�� ���� �� ����
				// �׷��� �̹� e�� �Ǽ����۰��ɽð��� now���� �ڷ� �̷��� ������ �� ����.
				ans[e] = max(ans[e], ans[now]);
				if (root[e] == 0) q.push(e);
			}
		}
		cout << ans[w] << endl;
	}
}