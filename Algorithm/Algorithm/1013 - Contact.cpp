#include <iostream>
#include <vector>
#include <string>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int n;

bool search(const string& str)
{
	if (str.length() == 0) return true;
	if (str.length() == 1) return false;

	if ("01" == str.substr(0, 2)) {
		if (search(str.substr(2))) return true;
	}
	if (str.length() < 4) return false;
	if ("100" == str.substr(0, 3)) {
		int n = 3;
		while (n != str.length()) {
			if (str[n] == '1') {
				int next = n + 1;
				if (next == str.length()) return true;
				if (str[next] == '0') {
					if (search(str.substr(next))) return true;
					else return false;
				}
				else {
					if (search(str.substr(next))) return true;
				}
			}
			++n;
		}
	}
	return false;
}

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (search(s)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}