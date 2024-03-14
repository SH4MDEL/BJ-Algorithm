#include <iostream>
#include <string>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;
string s, ioi;

int main()
{
	fastip; sws;
	
	cin >> n >> m >> s;
	for (int i = 0; i < n; ++i) {
		ioi += "IO";
	}
	ioi += "I";
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		auto result = s.find(ioi, i);
		if (result == string::npos) break;
		++ans;
		while (1) {
			int next = result + ioi.size();
			if (next + 1 >= s.size()) break;
			if (s[next] == 'O' && s[next + 1] == 'I') {
				result += 2;
				++ans;
			}
			else {
				break;
			}
		}
		i = result + ioi.size() - 1;
	}
	cout << ans;
}