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

int cache[100100];
int n, m;
vector<int> children[100100];

void dfs(int me, int value)
{
	cache[me] += value;
	for (const auto& child : children[me]) {
		dfs(child, cache[me]);
	}
}

int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		if (a == -1) continue;
		children[a].push_back(i);
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		cache[a] += b;
	}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i) {
		cout << cache[i] << " ";
	}
}