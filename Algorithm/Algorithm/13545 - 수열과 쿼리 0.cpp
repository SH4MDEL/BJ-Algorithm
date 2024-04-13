#include <iostream>
#include <ranges>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <cmath>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int root;

struct Query {
	int s, e, i;
	bool operator<(const Query& rhs) const {
		if (s / root != rhs.s / root) return (s / root < rhs.s / root);
		return (e < rhs.e);
	}
};
vector<Query> q;
vector<int> v, counter, rootcounter, ans;
vector<int> prefix;
deque<int> d[201010];
int n, m;

int GetPrefix(int i)
{
	return prefix[i + 1] + 5;
}

int main()
{
	fastip; sws;

	cin >> n;
	root = static_cast<int>(sqrt(n) + 1);
	v.resize(n);
	prefix.resize(n + 1);
	counter.resize(n + 1);
	rootcounter.resize(root + 1);
	for (auto& e : v) cin >> e;
	for (const auto& i : views::iota(1, n + 1)) prefix[i] = prefix[i - 1] + v[i - 1];
	cin >> m;
	q.resize(m);
	ans.resize(m);
	for (const auto& i : views::iota(0, m)) {
		cin >> q[i].s >> q[i].e;
		q[i].s -= 1, q[i].e -= 1, q[i].i = i;
	}
	sort(q.begin(), q.end());
	for (const auto& i : views::iota(q[0].s - 1, q[0].e + 1)) {
		int now = GetPrefix(i);
		if (d[now].size() >= 2) {
			int idx = d[now].back() - d[now].front();
			--counter[idx];
			--rootcounter[idx / root];
		}
		d[now].push_back(i);
		if (d[now].size() >= 2) {
			int idx = d[now].back() - d[now].front();
			++counter[idx];
			++rootcounter[idx / root];
		}
	}
	for (const auto& i : views::iota(0, root) | views::reverse) {
		if (rootcounter[i]) {
			for (const auto& j : views::iota(0, root) | views::reverse) {
				if (j + root * i > n) continue;
				if (counter[j + root * i]) {
					ans[q[0].i] = j + root * i;
					break;
				}
			}
			break;
		}
	}
	int left = q[0].s - 1, right = q[0].e;
	for (const auto& i : views::iota(1, m)) {
		int s = q[i].s - 1, e = q[i].e;

		if (s < left) {
			for (const auto& j : views::iota(s, left) | views::reverse) {
				int now = GetPrefix(j);
				if (d[now].size() >= 2) {
					int idx = d[now].back() - d[now].front();
					--counter[idx];
					--rootcounter[idx / root];
				}
				d[now].push_front(j);
				if (d[now].size() >= 2) {
					int idx = d[now].back() - d[now].front();
					++counter[idx];
					++rootcounter[idx / root];
				}
			}
		}
		if (right < e) {
			for (const auto& j : views::iota(right + 1, e + 1)) {
				int now = GetPrefix(j);
				if (d[now].size() >= 2) {
					int idx = d[now].back() - d[now].front();
					--counter[idx];
					--rootcounter[idx / root];
				}
				d[now].push_back(j);
				if (d[now].size() >= 2) {
					int idx = d[now].back() - d[now].front();
					++counter[idx];
					++rootcounter[idx / root];
				}
			}
		}

		if (left < s) {
			for (const auto& j : views::iota(left, s)) {
				int now = GetPrefix(j);
				if (d[now].size() >= 2) {
					int idx = d[now].back() - d[now].front();
					--counter[idx];
					--rootcounter[idx / root];
				}
				d[now].pop_front();
				if (d[now].size() >= 2) {
					int idx = d[now].back() - d[now].front();
					++counter[idx];
					++rootcounter[idx / root];
				}
			}
		}

		if (e < right) {
			for (const auto& j : views::iota(e + 1, right + 1) | views::reverse) {
				int now = GetPrefix(j);
				if (d[now].size() >= 2) {
					int idx = d[now].back() - d[now].front();
					--counter[idx];
					--rootcounter[idx / root];
				}
				d[now].pop_back();
				if (d[now].size() >= 2) {
					int idx = d[now].back() - d[now].front();
					++counter[idx];
					++rootcounter[idx / root];
				}
			}
		}

		for (const auto& j : views::iota(0, root) | views::reverse) {
			if (rootcounter[j]) {
				for (const auto& l : views::iota(0, root) | views::reverse) {
					if (l + root * j > n) continue;
					if (counter[l + root * j]) {
						ans[q[i].i] = l + root * j;
						break;
					}
				}
				break;
			}
		}

		left = s, right = e;
	}

	for (const auto& e : ans) cout << e << endl;
}