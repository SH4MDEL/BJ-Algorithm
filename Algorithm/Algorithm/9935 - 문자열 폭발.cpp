// GOLD IV 9935 - ¹®ÀÚ¿­ Æø¹ß

#include <iostream>
#include <string>
#include <stack>
#include <list>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

list<char> s;
string bomb;
stack<int> st;

int main()
{
    sws; fastip;

    string c;
    cin >> c >> bomb;
    for (auto itr : c) {
        s.push_back(itr);
    }
    auto now = bomb.begin();

    for (auto itr = s.begin(); itr != s.end(); ++itr) {
        if (*bomb.begin() == *itr) {
            st.push(0);
        }
        else if (!st.empty() && bomb[st.top() + 1] == *itr) {
            st.push(st.top() + 1);
        }
        else {
            while (!st.empty()) {
                st.pop();
            }
        }

        while (!st.empty()) {
            if (st.top() == bomb.length() - 1) {
                for (int i = 0; i < bomb.length(); ++i) {
                    itr = s.erase(itr);
                    if (s.size() && itr != s.begin()) --itr;
                    else if (s.size() && itr == s.begin()) {
                        if (*bomb.begin() == *itr) {
                            st.push(0);
                        }
                        else if (!st.empty() && bomb[st.top() + 1] == *itr) {
                            st.push(st.top() + 1);
                        }
                    }
                    st.pop();
                }
            }
            else {
                break;
            }

        }
        if (!s.size()) break;
    }

    if (!s.size()) cout << "FRULA";
    else {
        for (auto itr = s.begin(); itr != s.end(); ++itr) {
            cout << *itr;
        }
    }
}