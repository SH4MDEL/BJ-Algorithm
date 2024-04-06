#include <iostream>
#include <deque>
#include <ranges>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int n, m;
deque<int> d;
bool state[100100];

int main()
{
	fastip; sws;

	cin >> n;
	for (const auto& e : views::iota(0, n)) {
		cin >> state[e];
	}
	for (const auto& e : views::iota(0, n)) {
		int a; cin >> a;
		if (!state[e]) d.push_back(a);
	}
	cin >> m;
	for (const auto& i : views::iota(0, m)) {
		int a; cin >> a;
		if (!d.empty()) {
			d.push_front(a);
			a = d.back();
			d.pop_back();
		}
		cout << a << " ";
	}
}