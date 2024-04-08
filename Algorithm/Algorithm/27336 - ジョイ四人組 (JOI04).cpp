#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 1987654321 
#define endl "\n"
#define ll long long
using namespace std;

ll n, ans = inf;
vector<ll> v[4];
int main()
{
	fastip; sws;
	
	cin >> n;
	for (const auto& i : views::iota(0, 4)) {
		v[i].resize(n);
		for (auto& e : v[i]) cin >> e;
		sort(v[i].begin(), v[i].end());
	}

	vector<int> arr = { 0, 1, 2, 3 };
	do {
		if (arr[2] < arr[3]) continue;
		ll pre = -1;
		for (const auto& e : v[arr[0]]) {
			if (pre == e) continue;
			pre = e;
			int start = 0;
			int end = n;
			do {
				int mid = (start + end) / 2;
				ll left = e;
				ll right = v[arr[1]][mid];
				if (right - left < 0) {
					if (start + 1 == end) break;
					start = mid;
					continue;
				}
				if (right - left >= ans) {
					if (start + 1 == end) break;
					end = mid;
					continue;
				}

				auto l1 = lower_bound(v[arr[2]].begin(), v[arr[2]].end(), left);
				auto l2 = lower_bound(v[arr[3]].begin(), v[arr[3]].end(), left);

				if (l1 != v[arr[2]].end() && l2 != v[arr[3]].end() &&
					*l1 <= right && *l2 <= right) {
					ans = min(ans, right - left);
					if (start + 1 == end) break;
					end = mid;
				}
				else {
					if (start + 1 == end) break;
					start = mid;
				}
			} while (start < end);
		}
		
	} while (next_permutation(arr.begin(), arr.end()));

	cout << ans;
}