#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
#define to(n) views::iota(0, n)
#define rev views::reverse
using namespace std;

int n, c;
vector<int> v;

bool check(int dist, int least)
{
    int length = dist;
    if (!--least) return true;
    for (auto i : to(n) | views::drop(1)) {
        if (v[i] - v[i - 1] > length) {
            if (!--least) return true;
            length = dist;
        }
        else {
            length -= (v[i] - v[i - 1]);
        }
    }
    return false;
}

int main()
{
    fastip; sws;

    cin >> n >> c;
    v.resize(n);
    for (auto& e : v) cin >> e;
    ranges::sort(v);
    int s = 0, e = 1'000'000'000;
    while (s + 1 < e) {
        int m = (s + e) / 2;
        if (check(m, c)) {
            s = m;
        }
        else {
            e = m;
        }
    }
    cout << e;
}