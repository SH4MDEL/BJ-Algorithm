#include <iostream>
#include <ranges>
#include <algorithm>
#include <memory.h>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int n;
int people[10010];
vector<int> children[10010];
int cache[10010][2];

int dp(int me, int parent, int peek)
{
	if (children[me].size() == 1 && parent != -1) {
		if (peek == 1) return people[me];
		return 0;
	}
	if (cache[me][peek] != -1) return cache[me][peek];

	if (peek == 0) {
		int r = 0;
		for (const auto& child : children[me]) {
			if (child == parent) continue;
			r += max(dp(child, me, 0), dp(child, me, 1));
		}
		return cache[me][0] = r;
	}
	int r = 0;
	for (const auto& child : children[me]) {
		if (child == parent) continue;
		r += dp(child, me, 0);
	}
	return cache[me][1] = r + people[me];
}

int main()
{
	fastip; sws;
	memset(cache, -1, sizeof cache);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> people[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		children[a].push_back(b);
		children[b].push_back(a);
	}
	cout << max(dp(1, -1, 0), dp(1, -1, 1));
}