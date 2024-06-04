#include <iostream>
#include <string>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

string s, ans;
int cc, pc;

void printzero(int num)
{
	for (int i = 0; i < num; ++i) cout << "0000:";
}

int main()
{
	fastip; sws;

	cin >> s;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == ':') ++cc;
	}
	if (cc == 8) {
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == ':' && s[i + 1] == ':') {
				s.erase(i + 1, i + 1);
				break;
			}
		}
	}
	string tmp = "";
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == ':') {
			for (int i = 0; i < 4 - tmp.length(); ++i) {
				cout << "0";
			}
			cout << tmp << ":";
			tmp = "";
			if (i + 1 != s.length() && s[i + 1] == ':' && cc != 7) {
				printzero(7 - cc);
			}
		}
		else tmp.push_back(s[i]);
	}

	for (int i = 0; i < 4 - tmp.length(); ++i) {
		cout << "0";
	}
	cout << tmp;
}