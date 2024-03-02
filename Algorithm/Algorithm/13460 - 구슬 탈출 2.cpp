#include <iostream>
#include <algorithm>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

char map[12][12];
int n, m;

struct coord
{
	int x, y;

	bool operator==(const coord& rhs) const {
		return (x == rhs.x && y == rhs.y);
	}
	bool operator!=(const coord& rhs) const {
		return !(*this == rhs);
	}
	coord& operator=(const coord& rhs) {
		(*this).x = rhs.x;
		(*this).y = rhs.y;
		return (*this);
	}
};
coord o;

void up(coord& r, coord& b)
{
	coord* first = &r, *second = &b;
	if (r.y > b.y) swap(first, second);

	for (int i = first->y - 1; i > 0; --i) {
		if (map[i][first->x] == '#') break;
		first->y = i;
		if (map[i][first->x] == 'O') break;
	}
	for (int i = second->y - 1; i > 0; --i) {
		if (first->x == second->x && first->y == i && *first != o) break;
		if (map[i][second->x] == '#') break;
		second->y = i;
		if (map[i][second->x] == 'O') break;
	}
}

void right(coord& r, coord& b)
{
	coord* first = &r, * second = &b;
	if (r.x < b.x) swap(first, second);

	for (int i = first->x + 1; i < m; ++i) {
		if (map[first->y][i] == '#') break;
		first->x = i;
		if (map[first->y][i] == 'O') break;
	}
	for (int i = second->x + 1; i < m; ++i) {
		if (first->y == second->y && first->x == i && *first != o) break;
		if (map[second->y][i] == '#') break;
		second->x = i;
		if (map[second->y][i] == 'O') break;
	}
}

void down(coord& r, coord& b)
{
	coord* first = &r, * second = &b;
	if (r.y < b.y) swap(first, second);

	for (int i = first->y + 1; i < n; ++i) {
		if (map[i][first->x] == '#') break;
		first->y = i;
		if (map[i][first->x] == 'O') break;
	}
	for (int i = second->y + 1; i < n; ++i) {
		if (first->x == second->x && first->y == i && *first != o) break;
		if (map[i][second->x] == '#') break;
		second->y = i;
		if (map[i][second->x] == 'O') break;
	}
}

void left(coord& r, coord& b)
{
	coord* first = &r, * second = &b;
	if (r.x > b.x) swap(first, second);

	for (int i = first->x - 1; i > 0; --i) {
		if (map[first->y][i] == '#') break;
		first->x = i;
		if (map[first->y][i] == 'O') break;
	}
	for (int i = second->x - 1; i > 0; --i) {
		if (first->y == second->y && first->x == i && *first != o) break;
		if (map[second->y][i] == '#') break;
		second->x = i;
		if (map[second->y][i] == 'O') break;
	}
}

int search(coord r, coord b, int depth)
{
	if (depth == 10) return -1;
	int ans = inf;

	coord tr = r, tb = b;
	up(tr, tb);
	if (tb != o) {
		if (tr == o) return 1;
		int result = search(tr, tb, depth + 1);
		if (result != -1) ans = min(ans, result);
	}

	tr = r; tb = b;
	right(tr, tb);
	if (tb != o) {
		if (tr == o) return 1;
		int result = search(tr, tb, depth + 1);
		if (result != -1) ans = min(ans, result);
	}

	tr = r; tb = b;
	down(tr, tb);
	if (tb != o) {
		if (tr == o) return 1;
		int result = search(tr, tb, depth + 1);
		if (result != -1) ans = min(ans, result);
	}

	tr = r; tb = b;
	left(tr, tb);
	if (tb != o) {
		if (tr == o) return 1;
		int result = search(tr, tb, depth + 1);
		if (result != -1) ans = min(ans, result);
	}

	if (ans == inf) return -1;
	return ans + 1;
}

int main()
{
	fastip; sws;

	coord r, b;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			coord c{ j, i };
			if (map[i][j] == 'O') o = c;
			if (map[i][j] == 'R') r = c;
			if (map[i][j] == 'B') b = c;
		}
	}
	cout << search(r, b, 0);
}