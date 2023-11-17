#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define endl "\n"
#define ll long long
using namespace std;

int n, m;
vector<int> v;

int main() {
    fastip; sws;

    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int low = 0, high = 1'000'000'000;
    while (low + 1 < high) {
        [&]() {
            int mid = (low + high) / 2;
            int sum = 0, num = 1;
            for (const auto& e : v) {
                if (e > mid) {
                    low = mid;
                    return;
                }
                else if (sum + e > mid) {
                    sum = e;
                    ++num;
                }
                else {
                    sum += e;
                }
            }
            if (num <= m) {
                high = mid;
            }
            else {
                low = mid;
            }
        }();
    }
    cout << low + 1;
}