#include <iostream>
#include <math.h>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
int footmove[5][5][100100];
int chart[101010];

int find(int from, int to)
{
	if (from == 0) return 2;
	if (from == to) return 1;
	if (abs(from - to) == 2) return 4;
	return 3;
}

int dp(int depth, int left, int right)
{
	if (depth == n) return 0;
	int& res = footmove[left][right][depth];
	if (res != 0) return res;

	int minq = inf;
	if (chart[depth] != right) {
		minq = dp(depth + 1, chart[depth], right) + find(left, chart[depth]);
	}
	if (chart[depth] != left) {
		minq = min(minq, dp(depth + 1, left, chart[depth]) + find(right, chart[depth]));
	}

	return res = minq;
}

int main()
{
	fastip; sws;

	int num;
	for (; ; ++n) {
		cin >> num;
		if (num == 0) break;
		chart[n] = num;
	}
	cout << dp(0, 0, 0);
}