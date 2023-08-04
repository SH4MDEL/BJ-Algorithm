#include <iostream>
#include <queue>
#include <unordered_map>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
unordered_map<string, pair<string, string>> um;

void pre(const string& s)
{
    cout << s;
    if (um[s].first != ".") {
        pre(um[s].first);
    }
    if (um[s].second != ".") {
        pre(um[s].second);
    }
}

void mid(const string& s)
{
    if (um[s].first != ".") {
        mid(um[s].first);
    }
    cout << s;
    if (um[s].second != ".") {
        mid(um[s].second);
    }
}

void post(const string& s)
{
    if (um[s].first != ".") {
        post(um[s].first);
    }
    if (um[s].second != ".") {
        post(um[s].second);
    }
    cout << s;
}

int main()
{
    sws; fastip;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        string a, b, c;
        cin >> a >> b >> c;
        um.insert({ a, {b, c} });
    }
    pre("A");
    cout << endl;
    mid("A");
    cout << endl;
    post("A");
}