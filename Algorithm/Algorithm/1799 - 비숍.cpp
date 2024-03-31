#include <iostream>
#include <array>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

int n, ans;
array<array<int, 10>, 10> chessboard; 
// 0 -> 놓을 수 있음
// 1 -> 놓을 수 없음
// 2 -> 비숍 착수됨.
// -1 이하 -> 비숍의 공격 사정권

bool judge(const array<array<int, 10>, 10>& board, int y, int x)
{
	for (int i = -1; i > -n; --i) {
		if (y + i < 0 || x + i < 0) break;
		if (board[y + i][x + i] == 2) return false; }

	for (int i = 1; i < n; ++i) {
		if (y + i >= n || x + i >= n) break;
		if (board[y + i][x + i] == 2) return false; }

	for (int i = 1; i < n; ++i) {
		if (y + i >= n || x - i < 0) break;
		if (board[y + i][x - i] == 2) return false; }

	for (int i = 1; i < n; ++i) {
		if (y - i < 0 || x + i >= n) break;
		if (board[y - i][x + i] == 2) return false; }
	return true;
}

void start(array<array<int, 10>, 10>& board, int y, int x)
{
	board[y][x] = 2;

	for (int i = 1; i < n; ++i) {
		if (y + i >= n || x - i < 0) break;
		if (board[y + i][x - i] == 1 || board[y + i][x - i] == 2) continue;
		--board[y + i][x - i];
	}
	for (int i = 1; i < n; ++i) {
		if (y - i < 0 || x + i >= n) break;
		if (board[y - i][x + i] == 1 || board[y - i][x + i] == 2) continue;
		--board[y - i][x + i];
	}
}

void end(array<array<int, 10>, 10>& board, int y, int x)
{
	board[y][x] = 0;

	for (int i = 1; i < n; ++i) {
		if (y + i >= n || x - i < 0) break;
		if (board[y + i][x - i] == 1 || board[y + i][x - i] == 2) continue;
		++board[y + i][x - i];
	}
	for (int i = 1; i < n; ++i) {
		if (y - i < 0 || x + i >= n) break;
		if (board[y - i][x + i] == 1 || board[y - i][x + i] == 2) continue;
		++board[y - i][x + i];
	}
}

void search(array<array<int, 10>, 10>& board, int bishop, int y, int x, int least)
{
	if (bishop + least <= ans) return;

	int ny = y, nx = x;
	int now = ny + nx;
	while (now != n * 2 - 1) {
		if (board[ny][nx] == 0 && judge(board, ny, nx)) {
			start(board, ny, nx);
			ans = max(ans, bishop + 1);
			if (now >= n - 1) {
				search(board, bishop + 1, n - 1, now - n + 2, least - 1);
			}
			else {
				search(board, bishop + 1, now + 1, 0, least - 1);
			}
			end(board, ny, nx);
		}
		if (nx == n - 1) {
			ny = n - 1;
			nx = now - n + 2;
			--least;
		}
		else if (ny == 0) {
			ny = now + 1;
			nx = 0;
			--least;
		}
		else {
			--ny;
			++nx;
		}
		now = ny + nx;
	}
}

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> chessboard[i][j];
			chessboard[i][j] = 1 - chessboard[i][j];
		}
	}
	search(chessboard, 0, 0, 0, n * 2 - 1);
	cout << ans;
}