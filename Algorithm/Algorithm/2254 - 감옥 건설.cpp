#include <iostream>
#include <ranges>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

struct Dot {
	ll x, y;
	ll ox, oy;

	ll GetDX() const { return x - ox; }
	ll GetDY() const { return y - oy; }
	ll GetLength() const { return GetDX() * GetDX() + GetDY() * GetDY(); }

	bool operator<(const Dot& rhs) const {
		ll l = clamp(GetDX(), -1LL, 1LL);
		ll r = clamp(rhs.GetDX(), -1LL, 1LL);
		if (l != r) return l > r;
		if (!l || GetDY() * rhs.GetDX() == GetDX() * rhs.GetDY())
			return GetLength() < rhs.GetLength();
		return GetDY() * rhs.GetDX() < GetDX() * rhs.GetDY();
	}
	bool operator==(const Dot& rhs) const {
		return (x == rhs.x && y == rhs.y);
	}
	Dot& operator=(const Dot& rhs) {
		x = rhs.x, y = rhs.y, ox = rhs.ox, oy = rhs.oy;
		return *this;
	}
	Dot operator-(const Dot& rhs) const {
		return Dot{ x - rhs.x, y - rhs.y, ox, oy };
	}
};
int n, ans;
vector<Dot> v;
Dot prison, start;

ll ccw(const Dot& v1, const Dot& v2) {
	return clamp((v1.x * v2.y) - (v1.y * v2.x), -1LL, 1LL);
}

int main()
{
	fastip; sws;

	cin >> n >> prison.x >> prison.y;
	v.resize(n + 1);
	v[0] = prison;
	for (const auto& i : views::iota(1, n + 1)) {
		cin >> v[i].x >> v[i].y;
	}
	[&]() {
		while (v.size() > 2) {
			auto itr = min_element(v.begin(), v.end(), [](const Dot& a, const Dot& b) {
				if (a.y == b.y) return a.x < b.x;
				return a.y < b.y;
				});
			start = *itr;
			v.erase(itr);
			for (auto& [x, y, sx, sy] : v) {
				sx = start.x;
				sy = start.y;
			}
			sort(v.begin(), v.end());
			int now = 1;
			stack<Dot> s;
			s.push(start);
			s.push(v[0]);
			while (now < v.size()) {
				while (s.size() >= 2) {
					Dot d2 = v[now];
					Dot d1 = s.top(); s.pop();
					Dot d0 = s.top();
					Dot v1 = d2 - d1;
					Dot v0 = d1 - d0;
					if (ccw(v0, v1) == 1) {
						s.push(d1);
						break;
					}
				}
				s.push(v[now++]);
			}
			while (s.size() > 1) {
				auto d2 = s.top(); s.pop();
				auto d1 = s.top();
				v.erase(find(v.begin(), v.end(), d2));
				Dot v0 = d2 - d1;
				Dot v1 = prison - d1;
				if (d2 == prison) return;
				if (ccw(v0, v1) != 1) return;
			}

			++ans;
		}
	}();
	cout << ans;

}