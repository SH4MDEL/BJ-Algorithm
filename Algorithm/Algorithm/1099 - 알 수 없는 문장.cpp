#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <optional>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

string sentence;
vector<string> word[55];
unordered_map<string, string> sorted;
int n;
vector cache(55, optional<int>());
int s = inf, e = -inf;

int cost(const string& a, const string& b)
{
	int ans = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != b[i]) ++ans;
	}
	return ans;
}

int dp(const string& str)
{
	if (str == "") return 0;
	if (cache[str.length()].has_value()) return cache[str.length()].value();

	int ans = inf;
	for (int i = s; i <= e; ++i) {
		if (i > str.length()) break;
		if (word[i].empty()) continue;
		if (dp(str.substr(i)) == -1) continue;

		string substr = str.substr(0, i);
		string sorting = substr;
		sort(sorting.begin(), sorting.end());
		int minCost = inf;
		for (const auto& e : word[i]) {
			if (sorted[e] != sorting) continue;
			minCost = min(minCost, cost(e, substr));
		}
		if (minCost != inf) ans = min(ans, dp(str.substr(i)) + minCost);
	}
	if (ans == inf) return cache[str.length()].emplace(-1);
	return cache[str.length()].emplace(ans);
}

int main()
{
	fastip; sws;
	cin >> sentence >> n;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		if (sorted.count(str)) continue;
		word[str.length()].push_back(str);
		s = min(s, static_cast<int>(str.length()));
		e = max(e, static_cast<int>(str.length()));
		string sorting = str;
		sort(sorting.begin(), sorting.end());
		sorted.insert({ str, sorting });
	}
	cout << dp(sentence);
}