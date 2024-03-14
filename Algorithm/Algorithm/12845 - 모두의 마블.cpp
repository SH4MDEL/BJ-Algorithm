#include <iostream>
#include <list>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define ll long long
#define endl "\n"
using namespace std;

int n;
list<int> card;

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		card.push_back(num);
	}

	ll ans = 0;
	while (card.size() != 1) {
		auto itr = card.begin();
		int maximum = -inf;
		for (auto now = card.begin(); now != card.end(); ++now) {
			if (maximum < *now) {
				maximum = *now;
				itr = now;
			}
		}
		
		auto back = itr;
		auto front = itr;

		if (itr == card.begin()) {
			back = ++itr;
		}
		else {
			front = --itr;
		}
		ans += (*back + *front);
		if (*back > *front) card.erase(front);
		else card.erase(back);
	}
	cout << ans;
}