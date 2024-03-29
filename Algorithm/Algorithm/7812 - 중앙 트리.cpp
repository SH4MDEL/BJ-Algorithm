#include <iostream>
#include <vector>
#include <tuple>
#include <memory.h>
#include <unordered_map>
#include <stack>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

int n;
unordered_map<int, ll> cost[10010];
vector<int> children[10010];
int childrenNum[10010];
bool visited[10010];
ll sum;

int make_tree(int parent, int me, ll v)
{
	sum += v;
	childrenNum[me] = 1;
	if (parent != -1 && cost[me].size() == 1) return childrenNum[me];
	for (const auto& [child, value] : cost[me]) {
		if (child == parent) continue;
		children[me].push_back(child);
		childrenNum[me] += make_tree(me, child, v + value);
	}
	return childrenNum[me];
}

ll dfs()
{
	stack<tuple<int, ll>> s;
	s.push({ 0, sum });
	visited[0] = true;
	ll ans = sum;
	while (!s.empty()) {
		auto [now, value] = s.top(); s.pop();
		for (const auto& child : children[now]) {
			if (visited[child]) continue;
			visited[child] = true;
			int childSide = childrenNum[child] - 1;
			int parentSide = n - childSide - 2;
			ll newValue = cost[now][child] * (parentSide - childSide) + value;
			ans = min(ans, newValue);
			s.push({ child, newValue });
		}
	}
	return ans;
}

int main()
{
	fastip; sws;

	cin >> n;
	while (n) {
		for (int i = 0; i < n - 1; ++i) {
			int a, b, w;
			cin >> a >> b >> w;
			cost[a].insert({ b, w });
			cost[b].insert({ a, w });
		}
		make_tree(-1, 0, 0LL);
		cout << dfs() << endl;

		for (int i = 0; i < n; ++i) {
			cost[i].clear();
		}
		for (int i = 0; i < n; ++i) {
			children[i].clear();
		}
		sum = 0;
		memset(visited, false, sizeof visited);
		cin >> n;
	}
}