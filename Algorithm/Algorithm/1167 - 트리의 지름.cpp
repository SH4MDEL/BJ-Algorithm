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

int v;
vector<tuple<int, int>> children[100100];

tuple<int, int> search(int me, int parent)
{
	if (parent != -1 && children[me].size() == 1) return {0, 0};

	int maxround = 0, maxway1 = 0, maxway2 = 0;
	for (const auto& [child, dist] : children[me]) {
		if (child == parent) continue;
		auto [round, way] = search(child, me);
		way += dist;
		maxround = max(maxround, round);
		if (way >= maxway1) {
			maxway2 = maxway1;
			maxway1 = way;
		}
		else if (way > maxway2) {
			maxway2 = way;
		}
	}

	return { max(maxround, maxway1 + maxway2), maxway1 };
}

int main()
{
	fastip; sws;

	cin >> v;
	for (int i = 0; i < v; ++i) {
		int from, to, dist; 
		cin >> from >> to;
		while (to != -1) {
			cin >> dist;
			children[from].push_back({to, dist});
			cin >> to;
		}
	}
	auto [ans, _] = search(1, -1);
	cout << ans;
}