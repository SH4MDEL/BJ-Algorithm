#include <iostream>
#include <string>
#define endl "\n"
#define inf 987654321
using namespace std;

int n, m;

void solve(string str, int start)
{
	if (str.size() == m) {
		for (int i = 0; i < str.size(); ++i) {
			cout << str[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = start; i <= n; ++i) {
		solve(str + to_string(i), i);
	}
}

int main()
{
	cin >> n >> m;
	solve("", 1);
}