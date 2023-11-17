#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 3100000000 
#define endl "\n"
#define ll long long
using namespace std;

vector<ll> arr;
int n;
ll minimum = inf;
ll ans[3];

int main() {
    fastip; sws;

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; ++i) {
        int low = 0, high = n - 1;
        if (low == i) ++low;
        if (high == i) --high;
        while (low < high) {
            ll now = arr[low] + arr[high] + arr[i];
            if (minimum > abs(now)) {
                minimum = abs(now);
                ans[0] = arr[low], ans[1] = arr[high], ans[2] = arr[i];
                if (minimum == 0) break;
            }
            if (now < 0) {
                ++low;
                if (low == i) ++low;
            }
            else {
                --high;
                if (high == i) --high;
            }
        }
    }
    sort(ans, ans + 3);
    cout << ans[0] << " " << ans[1] << " " << ans[2];
}