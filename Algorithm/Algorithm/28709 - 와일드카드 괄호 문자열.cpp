#include <iostream>
#include <string>
#include <ranges>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

bool search(const string& s)
{
	int open = 0, close = 0, question = 0, wildcard = 0;
	for (const auto& c : s | views::reverse) {
		if (c == ')') ++open;
		if (c == '(') {
			if (!wildcard && open + question <= close) return false;
			++close;
		}
		if (c == '?') ++question;
		if (c == '*') ++wildcard;
	}
	open = 0, close = 0, question = 0, wildcard = 0;
	for (const auto& c : s) {
		if (c == '(') ++open;
		if (c == ')') {
			if (!wildcard && open + question <= close) return false;
			++close;
		}
		if (c == '?') ++question;
		if (c == '*') ++wildcard;
	}

	if (wildcard) return true;
	int convert = static_cast<int>(s.length() / 2) - open;
	int st = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(') ++st;
		if (s[i] == ')') --st;
		if (s[i] == '?') {
			if (convert) {
				--convert;
				++st;
			}
			else --st;
		}
	}
	if (st) return false;
	return true;
}

int main()
{
	fastip; sws;

	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		if (search(s)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}