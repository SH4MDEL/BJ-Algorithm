#include <iostream>
#include <string>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

ll fullBeat[60];

ll calc(ll num)
{
	if (num == 0 || num == 1) return num;
	for (ll i = 58; i >= 0; --i) {
		ll now = (1LL << i);
		if (now & num) {
			return (num - now + 1) + fullBeat[i - 1] + calc(num - now);
		}
	}

}

ll a, b;

int main()
{
	fastip; sws;
	cin >> a >> b;
	fullBeat[0] = 1LL;
	ll prev = 1LL;
	for (ll i = 1LL; i <= 58; ++i) {
		ll now = (1LL << i) + 1LL;
		fullBeat[i] = now - prev + fullBeat[i - 1] + fullBeat[i - 1];
	}
	cout << calc(b) - calc(a - 1);
}