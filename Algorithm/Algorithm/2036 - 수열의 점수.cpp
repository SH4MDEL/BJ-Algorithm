#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
#define to(n) views::iota(0, n)
#define rev views::reverse
using namespace std;

ll n, ans;
vector<ll> v;
ll neg, zero, pos;

int main()
{
    fastip; sws;
    cin >> n;
    v.resize(n);
    for (auto& e : v) cin >> e;
    ranges::sort(v);
    neg = ranges::lower_bound(v, 0) - v.begin();
    pos = v.end() - ranges::upper_bound(v, 0);
    zero = v.size() - neg - pos;
    for (int i = 0; i < neg - 1; i += 2) {
        ans += v[i] * v[i + 1];
    }
    if (neg % 2 && !zero) ans += v[neg - 1];

    for (int i = n - 1; i > neg + zero; i -= 2) {
        ans += (v[i] * v[i - 1] > v[i] + v[i - 1]) ?
            v[i] * v[i - 1] : v[i] + v[i - 1];
    }
    if (pos % 2) ans += v[neg + zero];

    cout << ans;
}