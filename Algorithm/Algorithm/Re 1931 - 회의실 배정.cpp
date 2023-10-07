#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

struct table {
	int s, e;
	bool operator<(const table& rhs) const {
		if (s == rhs.s) return e > rhs.e;
		return s > rhs.s;
	}
};

int n;
vector<table> v;

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int s, e;
		cin >> s >> e;
		v.emplace_back(s, e);
	}
	sort(v.begin(), v.end());
	int t = INT_MAX, ans = 0;
	for (const auto& e : v) {
		if (e.e <= t) {
			++ans;
			t = e.s;
		}
	}
	cout << ans;
}