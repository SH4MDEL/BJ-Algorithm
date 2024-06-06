#include <iostream>
#include <cmath>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int main()
{
	fastip; sws;

	double x, y, c;
	cin >> x >> y >> c;

	double s = 0.0, e = 3'000'000'001;
	while (e - s > 0.0001) {
		double m = (s + e) / 2.0;

		double h1 = sqrt(y * y - m * m);
		double h2 = sqrt(x * x - m * m);
		if ((h1 * h2) / (h1 + h2) >= c) s = m;
		else e = m;
	}
	cout << s;
}