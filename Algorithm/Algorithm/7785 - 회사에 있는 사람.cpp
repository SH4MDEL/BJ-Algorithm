#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

unordered_set<string> us;
vector<string> v;
int tc;

int main()
{
	sws; fastip;

	cin >> tc;
	for (int i = 0; i < tc; ++i) {
		string s, name;
		cin >> name >> s;
		if (s == "enter") {
			us.insert(move(name));
		}
		if (s == "leave") {
			us.erase(name);
		}
	}
	for (auto& name : us) {
		v.emplace_back(move(name));
	}
	sort(v.begin(), v.end(), [](const string& a, const string& b) {
		return a > b;
		});
	for (auto& name : v) {
		cout << name << endl;
	}
}