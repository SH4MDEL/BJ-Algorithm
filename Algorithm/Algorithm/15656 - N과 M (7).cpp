#include <iostream>
#include <string>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int num[8];
int n, m;

void solve(string str, int depth)
{
	if (depth == m) {
		cout << str << endl;
		return;
	}

	for (int i = 0; i < n; ++i) {
		solve(str + to_string(num[i]) + " ", depth + 1);
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
	solve("", 0);
}