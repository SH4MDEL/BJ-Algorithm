#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int n, l, ans;
vector<int> v;
vector<pair<int, int>> sol;
int cache[1010];

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		memset(cache, 0, sizeof cache);
		v.clear();
		cin >> l;
		v.resize(l);
		for (int j = 0; j < l; ++j) {
			cin >> v[j];
		}
		int a = -inf, s = 0, e = 0;
		for (int j = 1; j <= l; ++j) {
			cache[j] += cache[j - 1] + v[j - 1];
		}
		for (int j = 1; j <= l; ++j) {
			for (int k = 0; k < j; ++k) {
				int ns = k, ne = j;
				if (cache[ne] - cache[ns] > a) {
					s = ns, e = ne;
					a = cache[ne] - cache[ns];
				}
				else if (cache[ne] - cache[ns] == a &&
					(e - s > ne - ns)) {
					e = ne;
					s = ns;
				}
			}
		}
		ans += a;
		sol.push_back({ s + 1, e });
	}
	cout << ans << endl;
	for (const auto& [s, e] : sol) {
		cout << s << " " << e << endl;
	}
}