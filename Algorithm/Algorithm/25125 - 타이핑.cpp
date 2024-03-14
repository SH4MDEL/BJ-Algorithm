#include <iostream>
#include <string>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define ll long long
#define endl "\n"
using namespace std;

string s;

int main()
{
	fastip; sws;

	int ans = 0;
	bool toggle = false;

	cin >> s;
	for (int i = 0; i < s.size() - 1; ++i) {
		if (s[i] >= 'a') {
			if (!toggle) ++ans;
			else {
				if (s[i + 1] >= 'a') {
					toggle = !toggle;
				}
				ans += 2;
			}
		}
		else {
			if (toggle) ++ans;
			else {
				if (s[i + 1] <= 'Z') {
					toggle = !toggle;
				}
				ans += 2;
			}
		}
	}
	if ((s.back() >= 'a' && !toggle) || 
		(s.back() <= 'Z' && toggle)) ans += 1;
	else ans += 2;

	cout << ans;
}