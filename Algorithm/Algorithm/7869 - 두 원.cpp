#include <iostream>
#include <cmath>
#include <numbers>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

struct circle {
	double x, y, r;
};
circle c[2];

int main()
{
	fastip; sws;
	cout << fixed; cout.precision(3);

	cin >> c[0].x >> c[0].y >> c[0].r >> c[1].x >> c[1].y >> c[1].r;
	double d2 = (c[0].x - c[1].x) * (c[0].x - c[1].x) + (c[0].y - c[1].y) * (c[0].y - c[1].y);
	double d = sqrt(d2);

	if (c[0].r + c[1].r <= d) {
		cout << 0.0 << endl;
	}
	else if (abs(c[0].r - c[1].r) >= d) {
		if (c[0].r > c[1].r) {
			cout << c[1].r * c[1].r * numbers::pi;
		}
		else {
			cout << c[0].r * c[0].r * numbers::pi;
		}
	}
	else {
		double alpha = acos((d2 + c[0].r * c[0].r - c[1].r * c[1].r) / (2.0 * d * c[0].r));
		double beta = acos((d2 + c[1].r * c[1].r - c[0].r * c[0].r) / (2.0 * d * c[1].r));
		double h = c[0].r * sin(alpha);

		cout << (c[0].r * c[0].r * alpha) + (c[1].r * c[1].r * beta) - d * h;
	}
}