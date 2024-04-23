# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <iostream>
#include <ranges>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <cmath>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int root = 2000;
struct Query {
	int s, e, i;
	bool operator<(const Query& rhs) const {
		if (s / root != rhs.s / root) return (s / root < rhs.s / root);
		return (e < rhs.e);
	}
};
vector<Query> q;

vector<int> v, tmp;
vector<int> ans;
int counter[1000100];
int n, k;

int main()
{
	fastip; sws;

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	tmp = v;
	cin >> k;
	q.resize(k);
	ans.resize(k);
	for (int i = 0; i < k; ++i) {
		cin >> q[i].s >> q[i].e;
		q[i].s -= 1, q[i].e -= 1;
		q[i].i = i;
	}
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	for (int i = 0; i < n; ++i) {
		v[i] = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();
	}

	sort(q.begin(), q.end());

	int numCount = 0;
	for (int i = q[0].s; i <= q[0].e; ++i) {
		if (!counter[v[i]]) ++numCount;
		++counter[v[i]];
	}
	ans[q[0].i] = numCount;

	int left = q[0].s, right = q[0].e;
	for (int j = 1; j < k; ++j) {
		int start = q[j].s, end = q[j].e;
		if (right < end) {
			for (int i = right + 1; i <= end; ++i) {
				if (!counter[v[i]]) ++numCount;
				++counter[v[i]];
			}
		}
		if (start < left) {
			for (int i = left - 1; i >= start; --i) {
				if (!counter[v[i]]) ++numCount;
				++counter[v[i]];
			}
		}
		if (end < right) {
			for (int i = right; i > end; --i) {
				--counter[v[i]];
				if (!counter[v[i]]) --numCount;
			}
		}
		if (left < start) {
			for (int i = left; i < start; ++i) {
				--counter[v[i]];
				if (!counter[v[i]]) --numCount;
			}
		}
		ans[q[j].i] = numCount;
		left = start, right = end;
	}
	for (const auto& e : ans) cout << e << endl;
}