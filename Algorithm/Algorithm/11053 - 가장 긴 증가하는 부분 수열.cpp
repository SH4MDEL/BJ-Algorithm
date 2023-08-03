#include <iostream>
#include <cmath>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, maxNum;
int cache[1010];
int a[1010];

int main()
{
    sws; fastip;

    maxNum = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i] && cache[j] >= cache[i]) {
                cache[i] = cache[j] + 1;
                maxNum = max(maxNum, cache[i]);
            }
        }
    }
    cout << maxNum + 1;
}