#include <iostream>
#define inf 987654321 
#define endl "\n"
using namespace std;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	int r, s;
	cin >> r >> s;
	cout << (8 * r + 3 * s) - 28 << endl;
}