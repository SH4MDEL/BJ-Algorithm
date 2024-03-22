#include <iostream>
#include <stack>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

struct Circle {
	int x, r;
	bool prob;

	bool operator<(const Circle& rhs) const {
		if (x - r == rhs.x - rhs.r) return r < rhs.r;
		return x - r > rhs.x - rhs.r;
	}
	int GetStart() const { return x - r; }
	int GetEnd() const { return x + r; }
};
priority_queue<Circle> pq;
stack<Circle> s;
int n;

int main()
{
	fastip; sws;

	cin >> n;
	while (n--) {
		Circle c;
		cin >> c.x >> c.r;
		c.prob = false;
		pq.push(c);
	}
	// prob이란?
	// 원 우측에 새 원이 붙어서, 영역을 하나 만들 가능성이 있음을 의미한다.
	auto ans = pq.size() + 1;
	while (!pq.empty()) {
		auto now = pq.top(); pq.pop();

		while (!s.empty() && s.top().GetEnd() < now.GetStart()) {
			s.pop();
		}

		if (!s.empty()) {
			auto top = s.top();
			if (top.GetEnd() == now.GetStart()) {
				now.prob = top.prob;
				s.pop();
				while (!s.empty() && s.top().GetEnd() == now.GetStart()) {
					now.prob = s.top().prob;
					s.pop();
				}

				if (!s.empty() && s.top().GetEnd() == now.GetEnd() && now.prob) {
					++ans;
				}
			}
			else if (top.GetStart() == now.GetStart()) {
				now.prob = true;
			}
		}
		s.push(now);
	}
	cout << ans;
}