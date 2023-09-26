#include <iostream>
#include <string>
#include <stack>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, ans;
string s;
stack<char> st;

int main()
{
    fastip; sws;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (auto c : s) {
            if (!st.empty() && st.top() == c) {
                st.pop();
                continue;
            }
            st.push(c);
        }
        if (st.empty()) ++ans;
        while (!st.empty()) st.pop();
    }
    cout << ans;
}