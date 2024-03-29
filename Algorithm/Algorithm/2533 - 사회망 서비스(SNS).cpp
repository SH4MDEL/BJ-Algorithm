#include <iostream>
#include <vector>
#include <tuple>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

int n;
vector<int> fromto[1000100];

tuple<int, int> dp(int parent, int me)
{
	if (fromto[me].size() == 1 && parent != -1) return { 1, 0 };

	int yes = 1, no = 0;
	for (const auto& child : fromto[me]) {
		if (child == parent) continue;
		auto [cy, cn] = dp(me, child);
		yes += min(cy, cn);
		no += cy;
	}
	return { yes, no };
}

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		fromto[a].push_back(b);
		fromto[b].push_back(a);
	}
	auto [yes, no] = dp(-1, 1);
	cout << min(yes, no);
}