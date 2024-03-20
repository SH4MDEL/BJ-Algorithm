#include <iostream>
#include <string>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

struct Line {
	int s, e;

	bool operator<(const Line& rhs) const {
		return s > rhs.s;
	}
};
priority_queue<Line> pq;
int n;

int main()
{
	fastip; sws;

	cin >> n;
	while (n--) {
		Line l;
		cin >> l.s >> l.e;
		pq.push(l);
	}

	int ans = 0;
	int start = pq.top().s, end = pq.top().e; pq.pop();
	while (!pq.empty()) {
		auto now = pq.top(); pq.pop();

		if (now.s > end) {
			ans += end - start;
			start = now.s;
			end = now.e;
		}
		else {
			end = max(end, now.e);
		}
	}
	ans += end - start;
	cout << ans;
}