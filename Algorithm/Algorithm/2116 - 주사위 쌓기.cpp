#include <iostream>
#include <array>
#include <vector>
#include <ranges>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define endl "\n"
using namespace std;

int n;
vector<array<int, 6>> dices;
int side[6] = { 5, 3, 4, 1, 2, 0 };

int search(int depth, int top)
{
	if (depth == n) return 0;
	int nt, nd;
	for (auto i : views::iota(0, 6)) {
		if (dices[depth][i] == top) {
			nd = i;
			nt = side[i];
			break;
		}
	}
	int ans = 0;
	for (auto i : views::iota(0, 6)) {
		if (i == nd || i == nt) continue;
		ans = max(dices[depth][i], ans);
	}
	return search(depth + 1, dices[depth][nt]) + ans;
}

int main()
{
	fastip; sws;

	cin >> n;
	dices.resize(n);
	for (auto& dice : dices) {
		for (auto i : views::iota(0, 6))
			cin >> dice[i];
	}
	int ans = 0;
	for (auto i : views::iota(0, 6)) {
		ans = max(ans, search(0, dices[0][i]));
	}
	cout << ans;
}