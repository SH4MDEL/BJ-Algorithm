#include <iostream>
#include <string>
#include <list>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

list<char> l;
string s;
int n;

int main()
{
	fastip; sws;

	cin >> s;
	for (auto c : s) l.push_back(c);
	auto itr = l.end();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char query;
		cin >> query;
		if (query == 'L') {
			if (itr != l.begin()) {
				--itr;
			}
		}
		if (query == 'D') {
			if (itr != l.end()) {
				++itr;
			}
		}
		if (query == 'B') {
			if (itr != l.begin()) {
				--itr;
				itr = l.erase(itr);
			}
		}
		if (query == 'P') {
			char c;
			cin >> c;
			if (itr != l.begin()) {
				l.insert(itr, c);
			}
			else {
				l.push_front(c);
			}
		}
	}
	for (auto c : l) {
		cout << c;
	}
}