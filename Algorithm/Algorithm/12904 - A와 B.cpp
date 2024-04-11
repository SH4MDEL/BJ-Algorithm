#include <iostream>
#include <ranges>
#include <string>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

string s, e;

int search(int a, int b, string str)
{
	if (str.length() == s.length()) {
		if (str == s) return 1;
		return 0;
	}

	if (a > 0 && str.back() == 'A') {
		if (search(a - 1, b, str.substr(0, str.length() - 1))) return 1;
	}
	if (b > 0 && str.back() == 'B') {
		reverse(str.begin(), str.end() - 1);
		return search(a, b - 1, str.substr(0, str.length() - 1));
	}
	return 0;
}

int main()
{
	fastip; sws;

	int a = 0, b = 0;
	cin >> s >> e;
	for (const auto& c : s) {
		if (c == 'A') --a;
		else --b;
	}
	for (const auto& c : e) {
		if (c == 'A') ++a;
		else ++b;
	}
	cout << search(a, b, e);
}