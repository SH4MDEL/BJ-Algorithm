#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define mod 9901
#define ll long long
#define endl "\n"
using namespace std;

int v, ans, far;
vector<tuple<int, int>> children[10010];

void search(int me, int parent, int dist)
{
	if (ans < dist) {
		ans = dist;
		far = me;
	}
	if (parent != -1 && children[me].size() == 1) return;

	for (const auto& [child, next] : children[me]) {
		if (child == parent) continue;
		search(child, me, dist + next);
	}
}

int main()
{
	fastip; sws;

	cin >> v;
	for (int i = 0; i < v - 1; ++i) {
		int p, c, d;
		cin >> p >> c >> d;
		children[p].push_back({c, d});
		children[c].push_back({ p, d });
	}
	search(1, -1, 0);
	search(far, -1, 0);
	cout << ans;

}