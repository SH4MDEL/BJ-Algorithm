#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

vector<int> arr;
int n;
int minimum = inf;
int ans[2];

int main() {
    fastip; sws;

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int low = 0, high = n - 1;
    while (low < high) {
        int now = arr[low] + arr[high];
        if (minimum > abs(now)) {
            minimum = abs(now);
            ans[0] = arr[low], ans[1] = arr[high];
            if (minimum == 0) break;
        }
        if (now < 0) {
            ++low;
        }
        else --high;
    }
    cout << ans[0] << " " << ans[1];
}