#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int N;
char field[70][70];

void solve(int down, int up, int left, int right)
{
	if (up - down == 0) {
		printf("%c", field[down][left]);
		return;
	}
	bool diff = false;
	for (int i = down; i < up; i++) {
		for (int j = left; j < right; j++) {
			if (field[i][j] != field[down][left]) {
				diff = true;
			}
		}
	}
	if (!diff) {
		printf("%c", field[down][left]);
		return;
	}
	else {
		printf("(");
		solve(down + ((up - down) / 2 * 0), down + ((up - down) / 2 * 1), left + ((right - left) / 2 * 0), left + ((right - left) / 2 * 1));
		solve(down + ((up - down) / 2 * 0), down + ((up - down) / 2 * 1), left + ((right - left) / 2 * 1), left + ((right - left) / 2 * 2));
		solve(down + ((up - down) / 2 * 1), down + ((up - down) / 2 * 2), left + ((right - left) / 2 * 0), left + ((right - left) / 2 * 1));
		solve(down + ((up - down) / 2 * 1), down + ((up - down) / 2 * 2), left + ((right - left) / 2 * 1), left + ((right - left) / 2 * 2));
		printf(")");
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", &field[i]);
	}
	solve(0, N, 0, N);
}