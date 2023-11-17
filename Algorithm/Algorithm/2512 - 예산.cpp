#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define endl "\n"
#define ll long long
using namespace std;

int n, money;
vector<int> v;

int main() {
    fastip; sws;

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cin >> money;
    int sum = 0;
    for (const auto& e : v) {
        sum += e;
    }
    if (sum <= money) {
        cout << *max_element(v.begin(), v.end());
    }
    else {
        int low = 0, high = 100'000;
        while (low + 1 < high) {
            int mid = (low + high) / 2;

            int sum = 0;
            for (const auto& e : v) {
                if (e > mid) {
                    sum += mid;
                }
                else {
                    sum += e;
                }
            }
            if (sum > money) {
                high = mid;
            }
            else {
                low = mid;
            }
        }
        cout << low;
    }
}