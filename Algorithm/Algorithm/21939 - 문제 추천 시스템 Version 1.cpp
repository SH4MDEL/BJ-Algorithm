#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <string>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;

struct problem {
    int num;
    int level;

    bool operator<(const problem& rhs) const {
        if (level == rhs.level) return num < rhs.num;
        return level < rhs.level;
    }
};
set<problem> s;
unordered_map<int, int> um;

int main()
{
    fastip; sws;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        s.insert({ a, b });
        um.insert({ a, b });
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string str;
        cin >> str;
        if (str == "add") {
            int a, b;
            cin >> a >> b;
            s.insert({ a, b });
            um.insert({ a, b });
        }
        if (str == "recommend") {
            int a;
            cin >> a;
            if (a == 1) {
                cout << s.rbegin()->num << endl;
            }
            if (a == -1) {
                cout << s.begin()->num << endl;
            }
        }
        if (str == "solved") {
            int a;
            cin >> a;
            s.erase(s.find({ a, um[a] }));
            um.erase(um.find(a));
        }
    }
}