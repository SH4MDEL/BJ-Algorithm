#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int a1, a0, c, n;

int main()
{
	fastip; sws;
	cin >> a1 >> a0 >> c >> n;
	int d = a1 - c;
	if (d > 0 ||
		(d == 0 && a0 > 0) ||
		(d < 0 && n * d + a0 > 0)) cout << 0;
	else cout << 1;
}