#include <iostream>
#include <string>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
char field[105][105];

struct Coord {
	int y, x;

	int operator-(const Coord& rhs) const {
		return abs(rhs.y - y) + abs(rhs.x - x);
	}
};
Coord start, e;
vector<Coord> coord[4];

struct Ans {
	int num;
	int item;
	bool operator<(const Ans& rhs) const {
		if (num == rhs.num) return item < rhs.item;
		return num < rhs.num;
	}
};
vector<Ans> ans;

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> field[i][j];
			if (field[i][j] == 'H') { start.y = i; start.x = j; }
			if (field[i][j] == 'J') coord[0].push_back({ i, j });
			if (field[i][j] == 'C') coord[1].push_back({ i, j });
			if (field[i][j] == 'B') coord[2].push_back({ i, j });
			if (field[i][j] == 'W') coord[3].push_back({ i, j });
			if (field[i][j] == '#') { e.y = i; e.x = j; }
		}
	}

	int order[6][3] = { {0, 1, 2}, {0, 2, 1}, {1, 0, 2},{1, 2, 0}, {2, 1, 0}, {2, 0, 1} };
	for (int i = 0; i < 4; ++i) {
		int minimum = inf;
		for (int j = 0; j < 6; ++j) {
			int length = coord[i][order[j][0]] - start;
			length += coord[i][order[j][1]] - coord[i][order[j][0]];
			length += coord[i][order[j][2]] - coord[i][order[j][1]];
			length += e - coord[i][order[j][2]];
			minimum = min(minimum, length);
		}
		ans.push_back({ minimum, i });
	}
	switch ((*min_element(ans.begin(), ans.end())).item)
	{
	case 0:
		cout << "Assassin";
		break;
	case 1:
		cout << "Healer";
		break;
	case 2:
		cout << "Mage";
		break;
	case 3:
		cout << "Tanker";
		break;
	}
}