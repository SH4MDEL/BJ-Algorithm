#include <iostream>
#include <ranges>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
#define v views
#define r ranges
#define to(n) views::iota(0, n)
#define rev views::reverse
using namespace std;

ll x, y;

int main()
{
    fastip; sws;
    cin >> x >> y;
    ll s = 0, e = 1'000'000'001;
    while (s + 1 < e) {
        ll m = (s + e) / 2;
        if (y * 100 / x == (y + m) * 100 / (x + m)) {
            s = m;
        }
        else {
            e = m;
        }
    }
    if (e == 1'000'000'001) cout << -1;
    else cout << e;
}