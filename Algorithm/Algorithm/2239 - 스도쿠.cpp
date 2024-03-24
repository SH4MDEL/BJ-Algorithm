#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

int puzzle[9][9];
int counter;

bool judge(int y, int x, int num)
{
	for (int i = 0; i < 9; ++i) {
		if (puzzle[y][i] == num) return false;
		if (puzzle[i][x] == num) return false;
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (puzzle[i + (y / 3 * 3)][j + (x / 3 * 3)] == num) return false;
		}
	}
	return true;
}

bool backtracking(int line)
{
	if (line == 9) return true;
	if (line == 2) {

	}
	int key = 0b1111111110;
	for (int i = 0; i < 9; ++i) {
		if (puzzle[line][i] != 0) {
			key ^= (1 << puzzle[line][i]);
		}
	}
	if (!key) return backtracking(line + 1);

	int num = 0;
	for (int i = 0; i < 9; ++i) {
		if (puzzle[line][i] == 0) {
			while (key) {
				if (key % 2) {
					if (judge(line, i, num)) {
						puzzle[line][i] = num;
						if (backtracking(line)) return true;
						puzzle[line][i] = 0;
					}
				}
				key /= 2;
				++num;
			}
		}
	}
	return false;
}

int main()
{
	fastip; sws;

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			char c;
			cin >> c;
			puzzle[i][j] = c - '0';
			if (puzzle[i][j] == 0) ++counter;
		}
	}
	backtracking(0);

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << puzzle[i][j];
		}
		cout << endl;
	}
}