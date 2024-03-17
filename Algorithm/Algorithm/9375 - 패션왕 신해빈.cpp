#include <iostream>
#include <string>
#include <unordered_map>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int t, n;

int main()
{
	fastip; sws;
	cin >> t;
	while (t--) {
		unordered_map<string, int> um;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			string a, b;
			cin >> a >> b;
			++um[b];
		}
		int ans = 1;
		for (const auto& [_,e] : um) {
			ans *= (e + 1);
		}
		cout << ans - 1 << endl;
	}
}