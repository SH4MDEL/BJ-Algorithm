#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, counting;
long long sum;

int main()
{
    sws; fastip;

    cin >> n;

    sum = 1;
    for (int i = 1; i <= n; ++i) {
        sum *= i;
        while (sum % 10 == 0) {
            sum /= 10;
            ++counting;
        }
        if (sum > 10000) {
            sum %= 10000;
        }
    }
    cout << counting;
}