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

struct problem {
    int num;
    int level;
    int algo;
    
    bool operator<(const problem& rhs) const {
        if (level == rhs.level) return num < rhs.num;
        return level < rhs.level;
    }
};

set<problem> s;
set<problem> ps[101];
unordered_map<int, pair<int, int>> um;
int n, m;

int main()
{
    fastip; sws;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        s.insert({ a, b, c });
        ps[c].insert({ a, b, c });
        um.insert({ a, {b, c} });
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string str;
        cin >> str;
        if (str == "recommend") {
            int a, b;
            cin >> a >> b;
            if (b == 1) {
                cout << ps[a].rbegin()->num << endl;
            }
            if (b == -1) {
                cout << ps[a].begin()->num << endl;
            }
        }
        if (str == "recommend2") {
            int a;
            cin >> a;
            if (a == 1) {
                cout << s.rbegin()->num << endl;
            }
            if (a == -1) {
                cout << s.begin()->num << endl;
            }
        }
        if (str == "recommend3") {
            int a, b;
            cin >> a >> b;
            problem p{ -1, b, 0 };
            s.insert(p);
            auto itr = s.find(p);
            if (a == 1) {
                ++itr;
                if (itr == s.end()) cout << -1 << endl;
                else cout << itr->num << endl;
            }
            if (a == -1) {
                if (itr == s.begin()) cout << -1 << endl;
                else {
                    --itr;
                    cout << itr->num << endl;
                }
            }
            s.erase(s.find(p));
        }
        if (str == "add") {
            int a, b, c;
            cin >> a >> b >> c;
            s.insert({ a, b, c });
            ps[c].insert({ a, b, c });
            um.insert({ a, {b, c} });
        }
        if (str == "solved") {
            int a;
            cin >> a;
            auto level = um[a].first;
            auto algo = um[a].second;
            s.erase(s.find({a, level, algo}));
            ps[algo].erase(ps[algo].find({a, level, algo}));
            um.erase(um.find(a));
        }
    }
}