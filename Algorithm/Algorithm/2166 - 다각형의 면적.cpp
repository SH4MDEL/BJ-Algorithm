#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

int n;
vector<pair<double, double>> coordinate;

double ccw(pair<double, double> a, pair<double, double> b, pair<double, double> c)
{
	return ((a.first * b.second + b.first * c.second + c.first * a.second) -
		(a.first * c.second + c.first * b.second + b.first * a.second)) / 2;
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cout << fixed; cout.precision(1);

	cin >> n;
	double a, b, sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		coordinate.push_back(make_pair(a, b));
	}
	for (int i = 1; i < n - 1; ++i) {
		sum += ccw(coordinate[0], coordinate[i], coordinate[i + 1]);
	}
	cout << abs(sum) << endl;
}