// GOLD IV 17298 - ¿ÀÅ«¼ö

#include <iostream>
#include <vector>
#include <stack>
#include <list>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

vector<int> v;
vector<int> answer;
stack<int> s;
int n;

int main()
{
    sws; fastip;

    cin >> n;
    v.resize(n);

    for (auto& i : v) {
        cin >> i;
    }

    for (auto itr = v.rbegin(); itr != v.rend(); ++itr) {
        int ans = -1;
        while (!s.empty()) {
            if (s.top() > *itr) {
                ans = s.top();
                break;
            }
            else {
                s.pop();
            }
        }
        s.push(*itr);
        answer.push_back(ans);
    }
    for (auto itr = answer.rbegin(); itr != answer.rend(); ++itr) {
        cout << *itr << " ";
    }
}