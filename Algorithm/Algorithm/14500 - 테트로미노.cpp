#include <iostream>
#include <string>
#include <unordered_map>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;
int map[510][510];
int maximum = -inf;

void Block1(int y, int x)
{
	if (x + 4 > m) return;

	int sum = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y][x + 3];
	maximum = max(maximum, sum);
}
void Block2(int y, int x)
{
	if (y + 4 > n) return;

	int sum = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 3][x];
	maximum = max(maximum, sum);
}
void Block3(int y, int x)
{
	// ¤±
	if (y + 2 > n || x + 2 > m) return;

	int sum = map[y][x] + map[y + 1][x] + map[y][x + 1] + map[y + 1][x + 1];
	maximum = max(maximum, sum);
}
void Block4(int y, int x)
{
	if (y + 3 > n || x + 2 > m) return;

	int sum = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 2][x + 1];
	maximum = max(maximum, sum);
}
void Block5(int y, int x)
{
	if (y + 2 > n || x + 3 > m) return;

	int sum = map[y][x] + map[y + 1][x] + map[y][x + 1] + map[y][x + 2];
	maximum = max(maximum, sum);
}
void Block6(int y, int x)
{
	if (y + 2 > n || x + 3 > m) return;

	int sum = map[y + 1][x] + map[y + 1][x + 1] + map[y + 1][x + 2] + map[y][x + 2];
	maximum = max(maximum, sum);
}
void Block7(int y, int x)
{
	if (y + 3 > n || x + 2 > m) return;

	int sum = map[y][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y + 2][x + 1];
	maximum = max(maximum, sum);
}
void Block8(int y, int x)
{
	if (y + 3 > n || x + 2 > m) return;

	int sum = map[y][x + 1] + map[y + 1][x + 1] + map[y + 2][x + 1] + map[y + 2][x];
	maximum = max(maximum, sum);
}
void Block9(int y, int x)
{
	if (y + 2 > n || x + 3 > m) return;

	int sum = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 2];
	maximum = max(maximum, sum);
}
void Block10(int y, int x)
{
	if (y + 2 > n || x + 3 > m) return;

	int sum = map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 1][x + 2];
	maximum = max(maximum, sum);
}
void Block11(int y, int x)
{
	if (y + 3 > n || x + 2 > m) return;

	int sum = map[y][x] + map[y][x + 1] + map[y + 1][x] + map[y + 2][x];
	maximum = max(maximum, sum);
}
void Block12(int y, int x)
{
	if (y + 3 > n || x + 2 > m) return;

	int sum = map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 2][x + 1];
	maximum = max(maximum, sum);
}
void Block13(int y, int x)
{
	if (y + 2 > n || x + 3 > m) return;

	int sum = map[y + 1][x] + map[y + 1][x + 1] + map[y][x + 1] + map[y][x + 2];
	maximum = max(maximum, sum);
}
void Block14(int y, int x)
{
	if (y + 3 > n || x + 2 > m) return;

	int sum = map[y][x + 1] + map[y + 1][x + 1] + map[y + 1][x] + map[y + 2][x];
	maximum = max(maximum, sum);
}
void Block15(int y, int x)
{
	if (y + 2 > n || x + 3 > m) return;

	int sum = map[y][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y + 1][x + 2];
	maximum = max(maximum, sum);
}
void Block16(int y, int x)
{
	if (y + 2 > n || x + 3 > m) return;

	int sum = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 1];
	maximum = max(maximum, sum);
}
void Block17(int y, int x)
{
	if (y + 2 > n || x + 3 > m) return;

	int sum = map[y + 1][x] + map[y + 1][x + 1] + map[y][x + 1] + map[y + 1][x + 2];
	maximum = max(maximum, sum);
}
void Block18(int y, int x)
{
	if (y + 3 > n || x + 2 > m) return;

	int sum = map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 2][x];
	maximum = max(maximum, sum);
}
void Block19(int y, int x)
{
	if (y + 3 >= n || x + 2 > m) return;

	int sum = map[y][x + 1] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 2][x + 1];
	maximum = max(maximum, sum);
}



int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			Block1(i, j);
			Block2(i, j);
			Block3(i, j);
			Block4(i, j);
			Block5(i, j);
			Block6(i, j);
			Block7(i, j);
			Block8(i, j);
			Block9(i, j);
			Block10(i, j);
			Block11(i, j);
			Block12(i, j);
			Block13(i, j);
			Block14(i, j);
			Block15(i, j);
			Block16(i, j);
			Block17(i, j);
			Block18(i, j);
			Block19(i, j);
		}
	}
	cout << maximum << endl;
}