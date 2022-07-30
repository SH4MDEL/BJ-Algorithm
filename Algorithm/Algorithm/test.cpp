#include <iostream>
#define inf 987654321 
#define endl "\n"
using namespace std;

int all, sum, n;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> all >> n;
	int a, b;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		sum += a * b;
	}
	if (sum == all) cout << "Yes" << endl;
	else cout << "No" << endl;
	
}