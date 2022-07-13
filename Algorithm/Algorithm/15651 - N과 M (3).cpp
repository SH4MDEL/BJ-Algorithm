#include <iostream>
#include <string>
#define endl "\n"
#define inf 987654321
using namespace std;

int n, m;

void solve(string str)
{
	if (str.size() == m) {
		for (int i = 0; i < str.size(); ++i) {
			cout << str[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		solve(str + to_string(i));
	}
}

int main()
{
	cin >> n >> m;
	solve("");
}