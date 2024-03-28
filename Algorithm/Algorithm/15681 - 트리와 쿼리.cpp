#include <iostream>
#include <vector>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

int n, r, q;
int cache[100100];
vector<int> children[100100];

int make_tree(int parent, int me)
{
	if (cache[me] != -1) return cache[me];

	if (parent != -1 && children[me].size() == 1) return cache[me] = 1;

	int ans = 1;
	for (const auto& child : children[me]) {
		if (child == parent) continue;
		ans += make_tree(me, child);
	}
	return cache[me] = ans;
}

int main()
{
	fastip; sws;
	memset(cache, -1, sizeof cache);

	cin >> n >> r >> q;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		children[u].push_back(v);
		children[v].push_back(u);
	}
	make_tree(-1, r);
	for (int i = 0; i < q; ++i) {
		int u;
		cin >> u;
		cout << cache[u] << endl;
	}
}