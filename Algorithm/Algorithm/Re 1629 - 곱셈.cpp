#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

long long a, b, c;

long long solve(long long a, long long b)
{
    if (b == 1) return a % c;
    if (b % 2 == 1) {
        return ((solve(a, b / 2 + 1) % c) * (solve(a, b / 2) % c)) % c;
    }
    else return ((solve(a, b / 2) % c) * (solve(a, b / 2) % c)) % c;
}

int main()
{
    fastip; sws;

    cin >> a >> b >> c;
    cout << solve(a, b);
}