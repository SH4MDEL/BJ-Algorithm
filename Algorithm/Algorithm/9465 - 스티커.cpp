#include <iostream>
#define endl "\n"

int testcase, N;
int data[2][100000];
int cache[100000][3];

int solve(int n, int attached)
{
	if (N == n) {
		return 0;
	}
	if (cache[n][attached] != -1) {
		return cache[n][attached];
	}
	int answer = solve(n + 1, 0);
	if (attached != 1 && answer < solve(n + 1, 1) + data[0][n]) {
		answer = solve(n + 1, 1) + data[0][n];
	}
	if (attached != 2 && answer < solve(n + 1, 2) + data[1][n]) {
		answer = solve(n + 1, 2) + data[1][n];
	}
	return cache[n][attached] = answer;
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	std::cin >> testcase;
	for (int i = 0; i < testcase; ++i) {
		for (int j = 0; j < 100000; ++j) {
			for (int k = 0; k < 3; ++k) {
				cache[j][k] = -1;
			}
		}
		std::cin >> N;
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < N; ++k) {
				std::cin >> data[j][k];
			}
		}
		std::cout << solve(0, 0) << endl;
	}
}