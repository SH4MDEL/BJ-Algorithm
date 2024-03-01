#include <iostream>
#include <list>
#include <algorithm>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int n;
int cache[100100];
int num[320];

int search(int k)
{
	if (cache[k] != 0) return cache[k];

	int ans = inf;
	for (int i = 1; i < 320; ++i) {
		if (num[i] > k) break;
		ans = min(ans, search(k - num[i]) + 1);
	}
	return cache[k] = ans;
}

int main()
{
	fastip; sws;

	for (int i = 1; i < 320; ++i) {
		num[i] = i * i;
		cache[i * i] = 1;
	}
	cin >> n;
	cout << search(n);
}