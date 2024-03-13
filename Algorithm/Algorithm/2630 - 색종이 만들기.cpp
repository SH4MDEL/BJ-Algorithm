#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
bool map[130][130];

tuple<int, int> solve(int length, int y, int x)
{
	if (length == 1) {
		if (!map[y][x]) return { 1, 0 };
		else return { 0, 1 };
	}

	int half = length / 2;
	int white = 0, blue = 0;
	{	auto [w, b] = solve(half, y, x);
		white += w; blue += b; }
	{	auto [w, b] = solve(half, y + half, x);
		white += w; blue += b; }
	{	auto [w, b] = solve(half, y, x + half);
		white += w; blue += b; }
	{	auto [w, b] = solve(half, y + half, x + half);
		white += w; blue += b; }

	if (white == 0) return { 0, 1 };
	if (blue == 0) return { 1, 0 };
	return { white, blue };
}

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	auto [white, blue] = solve(n, 0, 0);
	cout << white << endl << blue;
}