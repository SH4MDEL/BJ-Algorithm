#include <iostream>
#include <ranges>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
#define to(n) views::iota(0, n)
#define rev views::reverse
using namespace std;

int n;
priority_queue<int> l;
priority_queue<int, vector<int>, greater<int>> r;

int main()
{
    fastip; sws;
    cin >> n;
    l.push(-98765);
    r.push(98765);
    while (n--) {
        int a; cin >> a;
        if ((l.size() + r.size()) % 2) {
            // r
            if (a > r.top()) r.push(a);
            else {
                l.push(a);
                r.push(l.top());
                l.pop();
            }
            cout << " " << l.top() << endl;
        }
        else {
            // l
            if (a < l.top()) l.push(a);
            else {
                r.push(a);
                l.push(r.top());
                r.pop();
            }
            cout << " " << l.top() << endl;
        }
    }
}