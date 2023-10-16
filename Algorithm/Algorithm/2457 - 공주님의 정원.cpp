#include <iostream>
#include <queue>
#include <algorithm>
#include <compare>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

struct date {
    int month, day;

    std::strong_ordering operator<=>(const date& rhs) const {
        if (month == rhs.month) {
            return day <=> rhs.day;
        }
        return month <=> rhs.month;
    }
    bool operator==(const date& rhs) const {
        return (month == rhs.month && day == rhs.day);
    }
};

struct flower {
    date s, e;

    bool operator<(const flower& rhs) const {
        if (e == rhs.e) {
            return s > rhs.s;
        }
        return e < rhs.e;
    }
};
priority_queue<flower> pq;
int n;

int main()
{
    fastip; sws;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        flower f;
        cin >> f.s.month >> f.s.day >> f.e.month >> f.e.day;
        if (f.e.month == 12) {
            f.e.day = 1;
        }
        if (f.s < f.e) pq.push(f);
    }

    int ans = 0;
    flower now;
    auto f = [&]() {
        while (!pq.empty()) {
            now = pq.top(); pq.pop();
            ++ans;

            if (now.s <= date{ 3, 1 }) break;

            while (!pq.empty()) {
                auto next = pq.top(); pq.pop();
                if (now.e == next.e) continue;

                if (now.s < next.e) {
                    next.e = now.s;
                    if (next.s < next.e) pq.push(next);
                    continue;
                }
                if (now.s == next.e) {
                    pq.push(next);
                    break;
                }
                if (next.e < now.s) {
                    ans = 0;
                    return;
                }
            }
        }
    };
    if (date{ 11, 30 } < pq.top().e) f();
    if (date{ 3, 1 } < now.s) ans = 0;

    cout << ans;
}