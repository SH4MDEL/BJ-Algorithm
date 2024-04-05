#include <iostream>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int n;
string s, e;
int cache[10100][15];

int Up(int from, int to)
{
	if (from <= to) return to - from;
	return 10 + to - from;
}

int Down(int from, int to)
{
	if (from >= to) return from - to;
	return 10 + from - to;
}

int Add(int from, int to)
{
	if (from + to >= 10) return from + to - 10;
	return from + to;
}


int dp(int depth, int rotate)
{
	if (depth == n) return 0;
	if (cache[depth][rotate] != -1) return cache[depth][rotate];

	char now = s[depth] + rotate;
	if (now > '9') now -= 10;

	if (now == e[depth])
		return cache[depth][rotate] = dp(depth + 1, rotate);

	int up = Up(now, e[depth]);
	int down = Down(now, e[depth]);
	return cache[depth][rotate] = min(dp(depth + 1, rotate) + down,
		dp(depth + 1, Add(rotate, up)) + up);
}

int main()
{
	fastip; sws;
	memset(cache, -1, sizeof cache);

	cin >> n;
	cin >> s >> e;
	cout << dp(0, 0) << endl;
}