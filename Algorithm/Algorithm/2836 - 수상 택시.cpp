#include <iostream>
#include <string>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int n, m;
struct Line {
	int s, e;

	bool operator<(const Line& rhs) const {
		return s < rhs.s;
	}
};
priority_queue<Line> pq;

int main()
{
	fastip; sws;

	cin >> n >> m;
	while (n--) {
		Line l;
		cin >> l.s >> l.e;
		if (l.s > l.e) pq.push(l);
	}

	Line item{ pq.top() }; pq.pop();
	ll ans = m;
	while (!pq.empty()) {
		auto now = pq.top(); pq.pop();
		if (item.e > now.s) {
			ans += (item.s - item.e) * 2;
			item.s = now.s;
			item.e = now.e;
		}
		else {
			item.e = min(item.e, now.e);
		}
	}
	ans += (item.s - item.e) * 2;
	cout << ans;
}