#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
int num[100100][3];
vector cache(2, vector(100100, vector(3, optional<int>())));

int dp(int pos, int depth, int isMin)
{
	if (depth == n) return cache[isMin][depth][pos].emplace(num[depth][pos]);
	if (cache[isMin][depth][pos].has_value()) return cache[isMin][depth][pos].value();

	auto func = [&](initializer_list<int> l) {
		if (isMin) return min(l);
		return max(l); };

	if (pos == 0) {
		return cache[isMin][depth][pos].emplace(
			func({ dp(0, depth + 1, isMin),
				dp(1, depth + 1, isMin) }) + num[depth][pos]);
	}
	else if (pos == 1) {
		return cache[isMin][depth][pos].emplace(
			func({ dp(0, depth + 1, isMin),
				dp(1, depth + 1, isMin), 
				dp(2, depth + 1, isMin) }) + num[depth][pos]);
	}
	return cache[isMin][depth][pos].emplace(
		func({ dp(1, depth + 1, isMin),
			dp(2, depth + 1, isMin) }) + num[depth][pos]);
}

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> num[i][0] >> num[i][1] >> num[i][2];
	}
	cout << dp(1, 0, 0) << " " << dp(1, 0, 1);
}