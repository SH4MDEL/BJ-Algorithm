#include <iostream>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int ax, ay, bx, by, cx, cy;
int v1x, v1y, v2x, v2y;

int main()
{
	fastip; sws;

	cin >> ax >> ay >> bx >> by >> cx >> cy;
	int num = (bx - ax) * (cy - by) - (by - ay) * (cx - bx);
	if (num > 0) cout << "1";
	else if (num < 0) cout << "-1";
	else cout << "0";
}