#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

string s, t;

bool search(string str)
{
	if (str.length() > t.length()) return false;
	{
		string a = str;
		reverse(a.begin(), a.end());
		if (t.find(str) == string::npos && t.find(a) == string::npos) return false;
	}

	if (str == t) return true;

	string b = str + "B";
	reverse(b.begin(), b.end());
	return search(b) || search(str + "A");
}

int main()
{
	sws; fastip;

	cin >> s >> t;

	if (search(s)) cout << "1";
	else cout << "0";
}