#include <iostream>
#include <string>
#include <unordered_set>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

unordered_set<string> us;
int n, m;

int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 1; j <= s.size(); ++j) {
			us.insert(s.substr(0, j));
		}
	}
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		if (us.count(s)) ++ans;
	}
	cout << ans;
}