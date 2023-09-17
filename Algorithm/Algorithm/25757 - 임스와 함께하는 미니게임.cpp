#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <unordered_set>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
char c;
unordered_set<string> us;

int main()
{
	fastip; sws;

	cin >> n >> c;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		us.insert(s);
	}
	if (c == 'Y') {
		cout << us.size() << endl;
	}
	if (c == 'F') {
		cout << us.size() / 2 << endl;
	}
	if (c == 'O') {
		cout << us.size() / 3 << endl;
	}
}