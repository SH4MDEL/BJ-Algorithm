#include <iostream>
#include <string>
#include <regex>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int main()
{
	fastip; sws;
	string s;
	regex re("(100+1+|01)+");
	cin >> s;
	if (regex_match(s, re)) cout << "SUBMARINE" << endl;
	else cout << "NOISE" << endl;
}