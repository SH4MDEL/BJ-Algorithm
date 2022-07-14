#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

int n, m;
int num[8];

void solve(string str, int start)
{
	if (str.size() == m) {
		for (int i = 0; i < str.size(); ++i) {
			cout << num[str[i] - '0'] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < n; ++i) {
		bool run = true;
		for (int j = 0; j < str.length(); ++j) {
			if ((str[j] - '0' == i)) {
				run = false;
			}
		}
		if (run) {
			solve(str + to_string(i), i);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	sort(num, num + n);
	solve("", 1);
}