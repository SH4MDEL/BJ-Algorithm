#include <iostream>
#include <string>
#include <stack>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int tc;
string s;
stack<int> st;
bool answer;

int main()
{
    sws; fastip;

    while (true) {
        while (!st.empty()) st.pop();
        getline(cin, s);

        if (s == ".") break;
        answer = true;

        for (const auto& c : s) {
            if (c == '(') {
                st.push(1);
            }
            if (c == ')') {
                if (st.empty()) {
                    answer = false;
                }
                else if (st.top() != 1) {
                    answer = false;
                }
                else {
                    st.pop();
                }
            }
            if (c == '{') {
                st.push(2);
            }
            if (c == '}') {
                if (st.empty()) {
                    answer = false;
                }
                else if (st.top() != 2) {
                    answer = false;
                }
                else {
                    st.pop();
                }
            }
            if (c == '[') {
                st.push(3);
            }
            if (c == ']') {
                if (st.empty()) {
                    answer = false;
                }
                else if (st.top() != 3) {
                    answer = false;
                }
                else {
                    st.pop();
                }
            }
        }
        if (st.empty() && answer) cout << "yes" << endl;
        else cout << "no" << endl;

    }
}