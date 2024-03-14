#include <iostream>
#include <unordered_set>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;

int main()
{
	fastip; sws;

	int ans = 0;

	cin >> n;

	int i = n % 10;
	if (i > 4) ans += (i - 1);
	else ans += i;
	n /= 10;

	int count = 9;
	while (n) {
		int i = n % 10;
		if (i > 4) ans += (i - 1) * count;
		else ans += i * count;

		n /= 10;
		count *= 9;
	}
	cout << ans;
}