#include <iostream>
#include <algorithm>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int n;
vector<pair<int, int>> v;

int power(int a)
{
	return a * a;
}

int dist(pair<int, int> a, pair<int, int> b)
{
	return power(a.first - b.first) + power(a.second - b.second);
}

int search(int s, int e)
{
	if (s + 1 == e) return dist(v[s], v[e]);
	if (s + 2 == e) return min({ dist(v[s], v[s + 1]), dist(v[s + 1], v[e]), dist(v[s], v[e]) });

	int m = (s + e) / 2;
	int result = min(search(s, m), search(m + 1, e));

	vector<pair<int, int>> candidate;
	for (int i = m; i >= s; --i) {
		if (power(v[m + 1].first - v[i].first) >= result) break;
		candidate.push_back(v[i]);
	}
	for (int i = m + 1; i <= e; ++i) {
		if (power(v[i].first - v[m].first) >= result) break;
		candidate.push_back(v[i]);
	}

	sort(candidate.begin(), candidate.end(), 
		[](const pair<int, int>& lhs, const pair<int, int>& rhs) {
		return lhs.second < rhs.second;
	});

	for (int i = 0; i < candidate.size(); ++i) {
		for (int j = i + 1; j < candidate.size(); ++j) {
			if (power(candidate[j].second - candidate[i].second) >= result) break;
			result = min(result, dist(candidate[i], candidate[j]));
		}
	}

	return result;
}

int main()
{
	fastip; sws;

	cin >> n;
	v.resize(n);
	for (auto& [x, y] : v) cin >> x >> y;
	sort(v.begin(), v.end());
	cout << search(0, n - 1);
}