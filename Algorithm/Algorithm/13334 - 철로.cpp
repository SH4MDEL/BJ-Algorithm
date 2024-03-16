#include <iostream>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int n, d;

struct Line {
	int s, e;
};

struct scmp {
	bool operator()(const Line& a, const Line& b) {
		return a.s > b.s;
	}
};
struct ecmp {
	bool operator()(const Line& a, const Line& b) {
		return a.e > b.e;
	}
};
priority_queue<Line, vector<Line>, ecmp> pq;
priority_queue<Line, vector<Line>, scmp> rail;

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		pq.push({ a, b });
	}
	cin >> d;
	int ans = 0;

	int start = -100'000'000;
	int end = start + d;
	while (!pq.empty()) {
		auto now = pq.top(); pq.pop();
		if (now.e - now.s > d) continue;
		if (now.e > end) {
			end = now.e;
			start = end - d;

			while (!rail.empty()) {
				if (rail.top().s < start) rail.pop();
				else break;
			}
		}
		rail.push(now);
		ans = max(ans, static_cast<int>(rail.size()));
	}
	cout << ans;
}