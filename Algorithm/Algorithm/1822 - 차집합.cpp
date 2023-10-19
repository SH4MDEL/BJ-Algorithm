#include <iostream>
#include <algorithm>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

vector<int> arr1, arr2, ans;
int n1, n2;

int main() {
    fastip; sws;

    cin >> n1 >> n2;
    arr1.resize(n1);
    arr2.resize(n2);
    for (int i = 0; i < n1; ++i) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; ++i) {
        cin >> arr2[i];
    }
    sort(arr2.begin(), arr2.end());
    for (int i = 0; i < n1; ++i) {
        if (!binary_search(arr2.begin(), arr2.end(), arr1[i])) {
            ans.push_back(arr1[i]);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (const auto& e : ans) {
        cout << e << " ";
    }
}