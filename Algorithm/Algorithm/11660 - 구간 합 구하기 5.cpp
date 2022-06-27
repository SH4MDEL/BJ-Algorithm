#include <iostream>
#define endl "\n"
using namespace std;
int N, M;

int origin[1025][1025];
int table[1025][1025];

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= N; ++j) {
			origin[i][j] = 0;
			table[i][j] = 0;
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> origin[i][j];
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			table[i][j] = origin[i][j] + table[i - 1][j] + table[i][j - 1] - table[i - 1][j - 1];
		}
	}
	int x1, y1, x2, y2;
	for (int i = 0; i < M; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		int sub1 = table[x2][y1 - 1];
		int sub2 = table[x1 - 1][y2];
		int sum = table[x1 - 1][y1 - 1];
		cout << table[x2][y2] - sub1 - sub2 + sum << endl;
	}
}