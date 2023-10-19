#include <iostream>
#include <algorithm>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

vector<int> a1, a2, a3, a4, sum1, sum2;
int n;

int main() {
    fastip; sws;

    cin >> n;
    a1.resize(n); a2.resize(n);
    a3.resize(n); a4.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a1[i] >> a2[i] >> a3[i] >> a4[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum1.push_back(a1[i] + a2[j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum2.push_back(a3[i] + a4[j]);
        }
    }
    long long count = 0;
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());
    for (const auto& e : sum1) {
        auto upper = upper_bound(sum2.begin(), sum2.end(), -e);
        auto lower = lower_bound(sum2.begin(), sum2.end(), -e);
        count += distance(lower, upper);
    }
    cout << count;
}