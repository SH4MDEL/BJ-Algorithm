#include <iostream>
#include <string>
#include <regex>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int t;

int main()
{
	fastip; sws;
	cin >> t;
	regex re("(100+1+|01)+");
	while (t--) {
		string s;
		cin >> s;
		if (regex_match(s, re)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}