#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, k, ans;
vector<int> v, w;

int main()
{
	fastip; sws;

	cin >> n >> k;
	v.resize(n);
	for (auto& e : v) {
		cin >> e;
	}
	if (n <= k) {
		cout << 0;
		return 0;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n - 1; ++i) {
		w.push_back(v[i + 1] - v[i]);
	}
	sort(w.begin(), w.end(), greater<int>());
	for (int i = k - 1; i < n - 1; ++i) {
		ans += w[i];
	}
	cout << ans;
}