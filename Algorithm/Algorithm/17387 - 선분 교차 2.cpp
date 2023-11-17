#include <iostream>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

ll ccw(ll vx1, ll vy1, ll vx2, ll vy2, ll vx3, ll vy3)
{
	ll result = (vx2 - vx1) * (vy3 - vy2) - (vx3 - vx2) * (vy2 - vy1);
	if (result > 0) return 1;
	else if (result < 0) return -1;
	else return 0;
}

bool check(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	if (x1 <= x3 && x3 <= x2 && y1 <= y3 && y3 <= y2) return true;
	if (x1 <= x3 && x3 <= x2 && y1 >= y3 && y3 >= y2) return true;
	if (x2 <= x3 && x3 <= x1 && y2 <= y3 && y3 <= y1) return true;
	if (x2 <= x3 && x3 <= x1 && y2 >= y3 && y3 >= y1) return true;
	return false;
}

int main()
{
	fastip; sws;

	ll x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	ll result1 = ccw(x1, y1, x2, y2, x3, y3);
	ll result2 = ccw(x1, y1, x2, y2, x4, y4);
	ll result3 = ccw(x3, y3, x4, y4, x1, y1);
	ll result4 = ccw(x3, y3, x4, y4, x2, y2);
	if (result1 == 0 || result2 == 0 || result3 == 0 || result4 == 0) {
		bool checker = false;
		if (result1 == 0) {
			if (check(x1, y1, x2, y2, x3, y3)) checker = true;
		}
		if (result2 == 0) {
			if (check(x1, y1, x2, y2, x4, y4)) checker = true;
		}
		if (result3 == 0) {
			if (check(x3, y3, x4, y4, x1, y1)) checker = true;
		}
		if (result4 == 0) {
			if (check(x3, y3, x4, y4, x2, y2)) checker = true;
		}
		if (checker) cout << 1;
		else cout << 0;
	}
	else if (((result1 == 1 && result2 == -1) || (result1 == -1 && result2 == 1)) &&
		((result3 == 1 && result4 == -1) || (result3 == -1 && result4 == 1))) cout << 1;
	else cout << 0;
}