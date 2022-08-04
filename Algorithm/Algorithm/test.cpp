#include <iostream>
#define inf 987654321 
#define endl "\n"
using namespace std;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);


	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		if (a % b == 0) {
			cout << "multiple" << endl;
			continue;
		}
		if (b % a == 0) {
			cout << "factor" << endl;
			continue;
		}
		cout << "neither" << endl;
	}
}