#include <iostream>
#include <ranges>
#include <bitset>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

constexpr int dy[] = { -1, 0, 0, 0, 1 };
constexpr int dx[] = { 0, -1, 0, 1, 0 };

bitset<100> click(int depth, const bitset<100>& now)
{
	bitset<100> tmp = now;
	int y = depth / 10;
	int x = depth % 10;
	for (int i = 0; i < 5; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < 10 && nx >= 0 && nx < 10) tmp.flip(ny * 10 + nx);
	}
	return tmp;
}

int search(int depth, const bitset<100>& now)
{
	if (depth == 100) {
		if (now.none()) return 0;
		return inf;
	}

	if (depth / 10 == 0) return min(
		search(depth + 1, now), 
		search(depth + 1, click(depth, now)) + 1);

	if (!now[depth - 10]) return search(depth + 1, now);
	return search(depth + 1, click(depth, now)) + 1;
}

int main()
{
	fastip; sws;

	bitset<100> start;
	for (const auto& i : views::iota(0, 10)) {
		for (const auto& j : views::iota(0, 10)) {
			char c; cin >> c;
			if (c == 'O') {
				start[i * 10 + j] = true;
			}
		}
	}
	int result = search(0, start);
	if (result >= inf) cout << -1;
	else cout << result;
}