#include <iostream>
#include <algorithm>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;
vector<int> v;
int minimum = 2100000000;

int main()
{
    fastip; sws;

    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int s = 0;
    int e = 0;

    while (s <= e && e != n) {
        int num = v[e] - v[s];
        if (num > m) {
            minimum = min(minimum, num);
            ++s;

        }
        else if (num == m) {
            minimum = num;
            break;
        }
        else {
            ++e;
        }

    }
    cout << minimum;
}