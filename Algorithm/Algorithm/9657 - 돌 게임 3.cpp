#include <iostream>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 1'000'000'000
#define ll long long
#define endl "\n"
using namespace std;

int n;
int cache[1010][2];

int dp(int least, int turn)
{
	if (least == 1 || least == 3 || least == 4) {
		return cache[least][turn] = turn;
	}
	if (cache[least][turn] != -1) return cache[least][turn];

	if (turn == dp(least - 1, 1 - turn)) return cache[least][turn] = turn;
	if (least - 3 > 0 && turn == dp(least - 3, 1 - turn)) return cache[least][turn] = turn;
	if (least - 4 > 0 && turn == dp(least - 4, 1 - turn)) return cache[least][turn] = turn;
	return cache[least][turn] = 1 - turn;
}

int main()
{
	fastip; sws;
	memset(cache, -1, sizeof cache);

	cin >> n;
	if (dp(n, 0)) cout << "CY";
	else cout << "SK";
}