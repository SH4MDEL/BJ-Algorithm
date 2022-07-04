#include <iostream>
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		if (n > m) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}