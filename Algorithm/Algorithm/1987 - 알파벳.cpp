#include <iostream>
#define inf 987654321 
#define endl "\n"
using namespace std;

char table[29][29];
int r, c;

int idistance = -inf;

void Search(int x, int y, int depth, int alpabet)
{
	if (table[y][x] >= 'A' && table[y][x] <= 'Z') {
		if (alpabet & (1 << (int)(table[y][x] - 'A'))) {
			return;
		}
		else {
			alpabet |= (1 << (int)(table[y][x] - 'A'));
			if (idistance < depth) {
				idistance = depth;
			}
		}
	}
	else {
		return;
	}
	Search(x - 1, y, depth + 1, alpabet);
	Search(x + 1, y, depth + 1, alpabet);
	Search(x, y - 1, depth + 1, alpabet);
	Search(x, y + 1, depth + 1, alpabet);
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	for (int i = 0; i < 29; ++i) {
		for (int j = 0; j < 29; ++j) {
			table[i][j] = '0';
		}
	}

	cin >> r >> c;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			cin >> table[i][j];
		}
	}
	Search(1, 1, 1, 0);
	cout << idistance << endl;

}