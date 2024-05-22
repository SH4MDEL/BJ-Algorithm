#include <iostream>
#include <string>
#include <stack>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 10987654321
#define ll long long
#define endl "\n"
using namespace std;

int n, m;
int cache[50];
bool fix[50];

int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int f; cin >> f;
		fix[f] = true;
	}
	cache[0] = 1;
	cache[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (fix[i] || fix[i - 1]) cache[i] = cache[i - 1];
		else cache[i] = cache[i - 1] + cache[i - 2];
	}
	cout << cache[n];
}