#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

ll n, k;
ll fx[100100];

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> fx[i];
	}
	cin >> k;

	if (fx[1] == k) cout << "T";
	else if (n == 1) cout << "F";
	else {
		bool up = false;
		if (fx[1] < k) up = !up;

		[&]() {
			for (int i = 2; i <= n; ++i) {
				if ((up && (fx[i] >= k * i)) || (!up && (fx[i] <= k * i))) {
					cout << "T";
					return;
				}
			}
			cout << "F";
		}();
	}
}