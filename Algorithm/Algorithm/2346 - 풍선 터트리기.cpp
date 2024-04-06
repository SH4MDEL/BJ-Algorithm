#include <iostream>
#include <deque>
#include <ranges>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int n;
struct Data {
	int v, i;
};

deque<Data> d;

int main()
{
	fastip; sws;

	cin >> n;
	d.resize(n);
	for (const auto& i : views::iota(0, n)) {
		cin >> d[i].v; d[i].i = i + 1;
	}
	int now = 0;
	while (!d.empty()) {
		auto now = d.front();  
		d.pop_front();
		cout << now.i << " ";
		if (d.empty()) break;
		if (now.v > 0) {
			now.v--;
			while (now.v--) {
				d.push_back(d.front());
				d.pop_front();
			}
		}
		else {
			while (now.v++) {
				d.push_front(d.back());
				d.pop_back();
			}
		}
	}
}