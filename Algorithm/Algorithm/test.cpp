#include <iostream>
#include <math.h>
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, sum;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n;
	while (n != 0) {
		sum += pow(n % 10, 5);
		n /= 10;
	}
	cout << sum << endl;
}