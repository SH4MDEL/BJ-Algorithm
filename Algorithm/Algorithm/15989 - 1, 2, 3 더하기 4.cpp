#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define ll long long
#define endl "\n"
using namespace std;

ll t, n;
ll cache[10010];

int main()
{
	fastip; sws;
	cache[0] = 1;
	for (int i = 1; i <= 3; ++i) {
		for (int j = i; j <= 10000; ++j) {
			cache[j] += cache[j - i];
		}
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << cache[n] << endl;
	}
}