#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int n, ans;
vector<int> v;

int main()
{
    fastip; sws;

    cin >> n;
    v.resize(n);
    for (auto& e : v) cin >> e;
    sort(v.begin(), v.end());
    for (auto i = v.begin(); i < v.end(); ++i) {
        [&]() {
            for (auto j = v.begin(); j < v.end(); ++j) {
                if (i == j) continue;
                auto lower = lower_bound(v.begin(), v.end(), *i - *j);
                auto upper = upper_bound(v.begin(), v.end(), *i - *j);
                for (auto itr = lower; itr != upper; ++itr) {
                    if (itr != v.end() && *itr == *i - *j && itr != i && itr != j) {
                        ++ans;
                        return;
                    }
                }

            }
        } ();
    }
    cout << ans;
}