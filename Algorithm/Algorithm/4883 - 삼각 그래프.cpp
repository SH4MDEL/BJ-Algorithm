#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 1'000'000'000
#define ll long long
#define endl "\n"
using namespace std;

int n, t;
int cache[100100][3];

int main()
{
	fastip; sws;

	cin >> n;
	while (n) {
		++t;
		int a, b, c;
		cin >> a >> b >> c;
		cache[1][0] = inf;
		cache[1][1] = b;
		cache[1][2] = cache[1][1] + c;

		for (int i = 2; i <= n; ++i) {
			cin >> a >> b >> c;
			cache[i][0] = min(cache[i - 1][0], cache[i - 1][1]) + a;
			cache[i][1] = min({ cache[i - 1][0], cache[i - 1][1], 
								cache[i - 1][2], cache[i][0] }) + b;
			cache[i][2] = min({ cache[i - 1][1], cache[i - 1][2], cache[i][1] }) + c;
		}
		cout << t << ". " << cache[n][1] << endl;

		cin >> n;
	}
}