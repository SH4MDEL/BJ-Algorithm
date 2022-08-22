#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int disjoint_set[110];
vector<pair<pair<int, int>, double>> vertex;
pair<double, double> stars[110];
int n;

int uf_find(int n) {
	if (disjoint_set[n] == -1) return n;
	return disjoint_set[n] = uf_find(disjoint_set[n]);
}

bool uf_union(int a, int b) {
	a = uf_find(a);
	b = uf_find(b);
	if (a == b) return false;
	disjoint_set[b] = a;
	return true;
}

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n; ++i) disjoint_set[i] = -1;

	for (int i = 0; i < n; ++i) {
		cin >> stars[i].first >> stars[i].second;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j) {
				vertex.push_back({{i, j}, sqrt((stars[j].first - stars[i].first) * (stars[j].first - stars[i].first) + (stars[j].second - stars[i].second) * (stars[j].second - stars[i].second)) });
			}
		}
	}
	sort(vertex.begin(), vertex.end(), [](const pair<pair<int, int>, double>& a, const pair<pair<int, int>, double>& b) {
		return a.second < b.second;
		});
	double ans = 0.0;
	int cnt = 0;
	for (const auto& elm : vertex) {
		if (uf_union(elm.first.first, elm.first.second)) {
			ans += elm.second;
			++cnt;
		}
		if (cnt == n) break;
	}
	cout << ans << endl;
}