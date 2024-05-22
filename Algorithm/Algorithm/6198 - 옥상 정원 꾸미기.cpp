#include <iostream>
#include <string>
#include <stack>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 10987654321
#define ll long long
#define endl "\n"
using namespace std;

ll n, num, ans;
stack<ll> s;

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		while (!s.empty() && s.top() <= num) {
			s.pop();
		}
		ans += s.size();
		s.push(num);
	}
	cout << ans;
}