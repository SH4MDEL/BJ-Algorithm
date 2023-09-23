#include <iostream>
#include <list>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int t;
string s;
list<char> l;

int main()
{
	fastip; sws;

	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> s;
		auto itr = l.begin();
		for (auto c : s) {
			if (c == '<') {
				if (itr != l.begin()) --itr;
			}
			else if (c == '>') {
				if (itr != l.end()) ++itr;
			}
			else if (c == '-') {
				if (itr != l.begin()) {
					--itr;
					itr = l.erase(itr);
				}
			}
			else {
				l.insert(itr, c);
			}
		}
		for (auto c : l) {
			cout << c;
		}
		cout << endl;
		l.clear();
	}
}