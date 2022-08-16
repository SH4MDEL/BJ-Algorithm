#include <iostream>
#include <string>
#define inf 987654321 
#define endl "\n"
using namespace std;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	string s;
	cin >> s;
	for (int i = 1; i <= s.size(); ++i) {
		cout << s[i - 1];
		if (i % 10 == 0) cout << endl;
	}
}