#include <iostream>
#include <vector>
#include <string>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

string t, p;
int fail[1000100];
vector<int> ans;

void kmp_set(const string& s) 
{
    for (int i = 1, j = 0; i < s.length(); ++i) {
        while (j > 0 && s[i] != s[j]) {
            j = fail[j - 1];
        }
        if (s[i] == s[j]) {
            fail[i] = ++j;
        }
    }
}

void kmp_find(const string& arr, const string& pat)
{
    for (int i = 0, j = 0; i < arr.length(); ++i) {
        while (j > 0 && arr[i] != pat[j]) {
            j = fail[j - 1];
        }

        if (arr[i] == pat[j]) {
           if (j == pat.length() - 1) {
                ans.push_back(i - pat.length() + 2);
                j = fail[j];
           }
           else {
               ++j;
           }
        }
    }
}

int main()
{
    fastip; sws;

    getline(cin, t);
    getline(cin, p);

    kmp_set(p);
    kmp_find(t, p);

    cout << ans.size() << endl;
    for (auto& i : ans)
        cout << i << " ";
}