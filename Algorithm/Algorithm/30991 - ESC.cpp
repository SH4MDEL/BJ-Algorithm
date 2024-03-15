#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

ll n, a, b, c;

int main()
{
	fastip; sws;

	b = c = 1;
	a = -1;
	cin >> n;
	ll ta, tb, tc;
	for (int i = 1; i < n; ++i) {
		ta = a, tb = b, tc = c;
		a = (ta - tc);
		b = (tb + tc);
		c = (2 * ta - 2 * tb + tc);
	}
	cout << a + b + c;
}