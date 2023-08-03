#include <iostream>
#include <cmath>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

bool k[550000];
int n;

void recursion(int n, int s)
{
    memset(k + s + n / 3, false, n / 3);
    if (n == 1) return;
    recursion(n / 3, s);
    recursion(n / 3, s + n / 3 * 2);
}

int main()
{
    sws; fastip;

    while (cin >> n) {
        int n3 = pow(3, n);
        memset(k, true, n3);
        recursion(n3, 0);
        for (int i = 0; i < n3; ++i) {
            if (k[i]) cout << "-";
            else cout << " ";
        }
        cout << endl;
    }
}