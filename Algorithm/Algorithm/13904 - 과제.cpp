#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
struct work {
	int d, w;
	bool operator<(const work& rhs) const {
		return w > rhs.w;
	}
};
vector<work> v;
vector<int> ans;

int main()
{
	fastip; sws;

	cin >> n;
	v.resize(n);
	ans.resize(1010);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].d >> v[i].w;
	}
	sort(v.begin(), v.end());

	for (const auto& e : v) {
		for (int i = e.d; i >= 1; --i) {
			if (ans[i] == 0) {
				ans[i] = e.w;
				break;
			}
		}
	}
	cout << accumulate(ans.begin(), ans.end(), 0);
}