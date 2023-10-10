#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, k;
struct jewel {
    int weight;
    int value;

    bool operator<(const jewel& rhs) const {
        return weight < rhs.weight;
    }
};
struct cmp {
    bool operator()(const jewel& a, const jewel& b) {
        return a.value < b.value;
    }
};
vector<jewel> v;
vector<int> bag;
priority_queue<jewel, vector<jewel>, cmp> pq;
long long ans;

int main()
{
    fastip; sws;

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a, b });
    }
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        bag.push_back(a);
    }
    sort(v.begin(), v.end());
    sort(bag.begin(), bag.end());

    auto itr = v.begin();
    for (const auto& size : bag) {
        while (itr != v.end() && (*itr).weight <= size) {
            pq.push(*itr);
            ++itr;
        }
        if (!pq.empty()) {
            ans += pq.top().value;
            pq.pop();
        }
    }
    cout << ans;
}