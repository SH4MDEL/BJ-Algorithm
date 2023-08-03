#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int a, b, c, d, e, f;
int x, y;

int main()
{
	sws; fastip;

	cin >> a >> b >> c >> d >> e >> f;

	[&]() {
		for (int i = -999; i <= 999; ++i) {
			for (int j = -999; j <= 999; ++j) {
				if (a * i + b * j == c && d * i + e * j == f) {
					cout << i << " " << j;
					return;
				}
			}
		}
	}();
}