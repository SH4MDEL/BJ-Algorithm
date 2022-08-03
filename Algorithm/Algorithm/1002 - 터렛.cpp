#include <iostream>
#include <math.h>
#define endl "\n"
#define inf 987654321
using namespace std;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);
	int t, x1, y1, r1, x2, y2, r2;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		long long d = (long long)pow(x1 - x2, 2) + (long long)pow(y1 - y2, 2);
		long long rp = (long long)pow(r1 + r2, 2);
		long long rm = (long long)pow(r1 - r2, 2);

		if (rm == 0 && d == 0) cout << "-1" << endl;
		else if (rm < d && d < rp) cout << "2" << endl;
		else if (d == rp) cout << "1" << endl;
		else if (d == rm) cout << "1" << endl;
		else cout << "0" << endl;
	}
}