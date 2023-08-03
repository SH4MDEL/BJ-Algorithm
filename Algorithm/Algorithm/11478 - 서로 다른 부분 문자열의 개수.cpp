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
string s;

int main()
{
	sws; fastip;

	cin >> s;
	for (int i = 0; i < s.length(); ++i) {				// i : 어디서 시작하나. 시작 지점의 위치
		for (int j = 1; j <= s.length() - i; ++j) {		// j : 몇 개의 단어를 고를 것인가
			string tag = s.substr(i, j);
			cout << tag << endl;
			us.insert(move(tag));
		}
	}
	cout << us.size();
}