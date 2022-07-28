#include <iostream>
#include <string>
#define inf 987654321 
#define endl "\n"
using namespace std;

string str;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		if (str.length() >= 6 && str.length() <= 9) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
}