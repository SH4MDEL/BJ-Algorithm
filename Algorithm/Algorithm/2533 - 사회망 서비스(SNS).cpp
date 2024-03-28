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

int cache[1000100][2];
int n;
vector<int> fromto[1000100];

int dp(int parent, int me, bool adopter)
{
	if (cache[me][adopter] != -1) return cache[me][adopter];

	if (fromto[me].size() == 1 && parent != -1) {
		if (adopter) return cache[me][adopter] = 0;
		return cache[me][adopter] = 1;
	}

	int sum1 = 1;
	for (const auto& child : fromto[me]) {
		if (child == parent) continue;
		sum1 += dp(me, child, true);
	}
	if (adopter) {
		int sum2 = 0;
		for (const auto& child : fromto[me]) {
			if (child == parent) continue;
			sum2 += dp(me, child, false);
		}
		return cache[me][adopter] = min(sum1, sum2);
	}
	return cache[me][adopter] = sum1;
}

int main()
{
	fastip; sws;
	memset(cache, -1, sizeof cache);

	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		fromto[a].push_back(b);
		fromto[b].push_back(a);
	}
	cout << dp(-1, 1, true);
}