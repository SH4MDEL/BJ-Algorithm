#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int n;
vector<pair<int, int>> v;

int main()
{
	fastip; sws;

    cin >> n;
    v.resize(n);
    for (int i = 0; auto& e : v) {
        cin >> e.first;
        e.second = i++;
    }

    stable_sort(v.begin(), v.end(), [](const pair<int, int>& l, const pair<int, int>& r) {
        return l.first < r.first;
    });
    
    int m = 0;
    for (int i = 0; i < n; ++i) {
        if (i > v[i].second) continue;
        if (m < v[i].second - i) {
            m = v[i].second - i;
        }
    }

    cout << m + 1 << endl;
}