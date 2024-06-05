#include <iostream>
#include <vector>
#include <memory.h>
#include <unordered_set>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

string s;
vector<string> v;
int n;
int cache[110];

bool dp(const string& now, int depth)
{
	if (now == "") return true;
	if (cache[depth] != -1) return cache[depth];

	for (const auto& str : v) {
		if (str.length() <= now.length()) {
			if (str == now.substr(0, str.length())) {
				if (dp(now.substr(str.length()), depth + str.length())) {
					return cache[depth] = 1;
				}
			}
		}
	}
	return cache[depth] = 0;
}

int main()
{
	fastip; sws;
	memset(cache, -1, sizeof cache);

	cin >> s >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	cout << dp(s, 0) ? 1 : 0;
}