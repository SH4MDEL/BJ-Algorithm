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
tuple<int, int> cache[200200];
int value[200200];
vector<int> children[200200];

tuple<int, int> dp(int me)
{
	if (children[me].empty()) return cache[me] = { -inf, 0 };

	int yes = 0, no = 0;
	for (const auto& child : children[me]) {
		auto [cy, cn] = dp(child);
		no += max(cy, cn);
	}
	for (const auto& menti : children[me]) {
		int maximum = no;
		auto [cy, cn] = cache[menti];
		maximum -= max(cy, cn);
		maximum += cn + value[me] * value[menti];
		yes = max(yes, maximum);
	}
	return cache[me] = { yes, no };
}

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int a;
		cin >> a;
		children[a].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> value[i];
	}
	auto [yes, no] = dp(1);
	cout << max(yes, no) << endl;
}