#include <iostream>
#include <algorithm>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
vector<int> arr;
vector<int> sum;

int main() {
    fastip; sws;

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            sum.push_back(arr[i] + arr[j]);
        }
    }
    sort(sum.begin(), sum.end());
    for (auto itr = arr.rbegin(); itr != arr.rend(); ++itr) {
        for (const auto& s : sum) {
            if (s > *itr) break;
            if (binary_search(arr.begin(), arr.end(), *itr - s)) {
                cout << *itr;
                return 0;
            }
        }
    }
}