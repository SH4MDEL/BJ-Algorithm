#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;
int num[8];
unordered_set<string> have;

void solve(string str, int depth, int last)
{
	if (depth == m) {
		if (have.count(str)) return;
		cout << str << endl;
		have.insert(str);
		return;
	}

	for (int i = last; i < n; ++i) {
		solve(str + to_string(num[i]) + " ", depth + 1, i);
	}
}

int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	sort(num, num + n);
	solve("", 0, 0);
}