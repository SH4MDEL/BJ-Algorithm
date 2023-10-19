#include <iostream>
#include <algorithm>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, k, s;
int work[410][410];

int main() {
    fastip; sws;

    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        work[a][b] = 1;
    }

    for (int m = 1; m <= n; ++m) {
        for (int s = 1; s <= n; ++s) {
            for (int e = 1; e <= n; ++e) {
                if (work[s][m] && work[m][e]) {
                    work[s][e] = 1;
                }
            }
        }
    }

    cin >> s;
    for (int i = 0; i < s; ++i) {
        int a, b;
        cin >> a >> b;
        if (work[a][b] != 0) cout << -1 << endl;
        else if (work[b][a] != 0) cout << 1 << endl;
        else cout << 0 << endl;
    }
}