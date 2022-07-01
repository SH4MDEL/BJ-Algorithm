#include <iostream>
#define inf 987654321 
#define endl "\n"
using namespace std;

char table[102][102];
char rgtable[102][102];
int n;
int rgcount = 0, ncount = 0;

void Search(int x, int y, char color)
{
	if (table[y][x] != color) {
		return;
	}
	table[y][x] = 'K';
	Search(x - 1, y, color);
	Search(x + 1, y, color);
	Search(x, y - 1, color);
	Search(x, y + 1, color);
}

void RGSearch(int x, int y, char color)
{
	if (rgtable[y][x] != color) {
		return;
	}
	rgtable[y][x] = 'K';
	RGSearch(x - 1, y, color);
	RGSearch(x + 1, y, color);
	RGSearch(x, y - 1, color);
	RGSearch(x, y + 1, color);
}

void AllSearch()
{
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (table[i][j] != 'K') {
				++ncount;
				Search(j, i, table[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (rgtable[i][j] != 'K') {
				++rgcount;
				RGSearch(j, i, rgtable[i][j]);
			}
		}
	}
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	for (int i = 0; i < 102; ++i) {
		for (int j = 0; j < 102; ++j) {
			table[i][j] = 'K';
		}
	}
	for (int i = 0; i < 102; ++i) {
		for (int j = 0; j < 102; ++j) {
			rgtable[i][j] = 'K';
		}
	}
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> table[i][j];
			if (table[i][j] == 'G') {
				rgtable[i][j] = 'R';
				continue;
			}
			rgtable[i][j] = table[i][j];
		}
	}
	AllSearch();
	cout << ncount << " " << rgcount << endl;
}