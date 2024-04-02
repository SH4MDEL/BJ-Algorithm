#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
#define ull unsigned ll
using namespace std;

ull a, b;
ull gcd(ull a, ull b)
{
	return a % b == 0 ? b : gcd(b, a % b);
}

int main()
{
	fastip; sws;
	cin >> a >> b;
	cout << a * b / gcd(a, b);
}