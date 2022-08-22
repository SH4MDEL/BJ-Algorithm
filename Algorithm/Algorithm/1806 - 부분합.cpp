#include <iostream>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'000;
using namespace std;

int num[100100];
int n, w;

int main()
{
	fastip; sws;
	cin >> n >> w;
	for (int i = 0; i < n; ++i) { cin >> num[i]; }

	int sum = num[0], minimum = inf;
	int s = 0, e = 0;
	while (s <= e && e < n) {
		if (sum > w) {
			minimum = min(minimum, e - s + 1);
			sum -= num[s];
			++s;
		}
		else if (sum == w) {
			minimum = min(minimum, e - s + 1);
			++e;
			sum += num[e];
		}
		else {
			++e;
			sum += num[e];
		}
	}
	if (minimum == inf) cout << "0" << endl;
	else cout << minimum << endl;
}