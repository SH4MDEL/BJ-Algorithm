#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

unordered_set<string> s;
int num[8];
int n, m;

void solve(string str, int depth, int key)
{
	if (depth == m) {
		if (!s.count(str)) {
			s.insert(str);
			cout << str << endl;
		}
		return;
	}

	for (int i = 0; i < n; ++i) {
		if ((key & (1 << i)) == 0) {
			solve(str + to_string(num[i]) + " ", depth + 1, key | (1 << i));
		}
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