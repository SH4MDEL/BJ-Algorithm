#include <iostream>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, l;

struct Data {
    int num, index;
};
struct cmp {
    bool operator()(const Data& a, const Data& b) {
        if (a.num == b.num) return a.index > b.index;
        return a.num > b.num;
    }
};
priority_queue<Data, vector<Data>, cmp> pq;

int main()
{
    fastip; sws;

    cin >> n >> l;
    for (int i = 1; i <= n; ++i) {
        Data d;
        d.index = i;
        cin >> d.num;
        pq.push(d);

        while (true) {
            auto now = pq.top();
            if (now.index < i - l + 1) {
                pq.pop();
                continue;
            }
            cout << now.num << " ";
            break;
        }
    }
}