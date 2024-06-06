#include <iostream>
#include <cmath>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

struct dot {
	double x, y;

	double Incline(const dot& rhs) {
		return (y - rhs.y) / (x - rhs.x);
	}
	double Length(const dot& rhs) {
		return sqrt((x - rhs.x) * (x - rhs.x) + (y - rhs.y) * (y - rhs.y));
	}
};
dot d[3];

int main()
{
	fastip; sws;

	for (int i = 0; i < 3; ++i) cin >> d[i].x >> d[i].y;
	if ((d[0].x - d[1].x == 0.0 && d[0].x - d[2].x == 0.0) || 
		(d[0].Incline(d[1]) == d[0].Incline(d[2]))) {
		cout << "-1.0" << endl;
	}
	else {
		cout << fixed;
		cout.precision(16);
		double length[3];
		length[0] = (d[0].Length(d[1]) + d[1].Length(d[2])) * 2.0;
		length[1] = (d[1].Length(d[2]) + d[2].Length(d[0])) * 2.0;
		length[2] = (d[2].Length(d[0]) + d[0].Length(d[1])) * 2.0;
		cout << *max_element(length, length + 3) - *min_element(length, length + 3);
	}
}