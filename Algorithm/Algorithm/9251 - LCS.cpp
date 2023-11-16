#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

int table[1002][1002];
string a, b;

int maxnum = -1;

//  A C A Y K P
//C 0 1 1 1 1 1
//A 1 1 2 2 2 2
//P 1 1 2 2 2 3
//C 1 2 2 2 2 3
//A 1 2 3 3 3 3 
//K 1 2 3 3 4 4

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	for (int i = 0; i < 1002; ++i) {
		for (int j = 0; j < 1002; ++j) {
			table[i][j] = 0;
		}
	}
	cin >> a >> b;
	for (int i = 1; i <= b.length(); ++i) {
		for (int j = 1; j <= a.length(); ++j) {
			if (a[j - 1] == b[i - 1] && table[i - 1][j] == table[i][j - 1]) {
				table[i][j] = table[i - 1][j - 1] + 1;
			}
			else {
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
			}
		}
	}
	cout << table[b.length()][a.length()] << endl;
}