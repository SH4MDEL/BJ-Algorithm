#include <iostream>
#include <algorithm>
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, sum;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	while (true) {
		cin >> n;
		if (n == -1) break;
		sum += n;
	}
	cout << sum;
}