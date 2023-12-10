#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, k, ans;
vector<int> tab, v, counter;

int main()
{
	fastip; sws;

	cin >> n >> k;
	tab.resize(n);
	v.resize(k + 1);
	counter.resize(k + 1);
	for (int i = 1; i <= k; ++i) {
		cin >> v[i];
		++counter[v[i]];
	}
	for (int i = 1; i <= k; ++i) {
		[&]() {
			// �̹� ���� �ִ���
			for (auto& e : tab) {
				if (e == v[i]) {
					--counter[v[i]];
					return;
				}
			}
			// ������ ����ִ� ĭ �ִ���
			for (auto& e : tab) {
				if (e == 0) {
					--counter[v[i]];
					e = v[i];
					return;
				}
			}
			// ������ ���� �ƿ� �� ���� �̴´�.
			for (auto& e : tab) {
				if (counter[e] == 0) {
					--counter[v[i]];
					e = v[i];
					++ans;
					return;
				}
			}
			// ������ ���� ���߿� ���� �̴´�.
			vector<int> marked;
			marked.resize(k + 1);
			int marking = 0;
			for (int j = i + 1; j <= k; ++j) {
				for (auto& e : tab) {
					if (e == v[j]) {
						if (marked[e] == 0) {
							marked[e] = 1;
							++marking;
						}
						if (marking == n) {
							--counter[v[i]];
							e = v[i];
							++ans;
							return;
						}
					}
				}
			}
		}();
	}
	cout << ans;
}