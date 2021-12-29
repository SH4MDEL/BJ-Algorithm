#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int N;
int field[2200][2200];
int answer[3];

void solve(int left, int right, int down, int up)
{
	if (right - left == 0) {
		answer[field[down][left] + 1]++;
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
		answer[field[down][left] + 1]++;
		return;
	}
	else {
		solve(left + ((right - left) / 3 * 0), left + ((right - left) / 3 * 1), down + ((up - down) / 3 * 0), down + ((up - down) / 3 * 1));
		solve(left + ((right - left) / 3 * 0), left + ((right - left) / 3 * 1), down + ((up - down) / 3 * 1), down + ((up - down) / 3 * 2));
		solve(left + ((right - left) / 3 * 0), left + ((right - left) / 3 * 1), down + ((up - down) / 3 * 2), down + ((up - down) / 3 * 3));
		solve(left + ((right - left) / 3 * 1), left + ((right - left) / 3 * 2), down + ((up - down) / 3 * 0), down + ((up - down) / 3 * 1));
		solve(left + ((right - left) / 3 * 1), left + ((right - left) / 3 * 2), down + ((up - down) / 3 * 1), down + ((up - down) / 3 * 2));
		solve(left + ((right - left) / 3 * 1), left + ((right - left) / 3 * 2), down + ((up - down) / 3 * 2), down + ((up - down) / 3 * 3));
		solve(left + ((right - left) / 3 * 2), left + ((right - left) / 3 * 3), down + ((up - down) / 3 * 0), down + ((up - down) / 3 * 1));
		solve(left + ((right - left) / 3 * 2), left + ((right - left) / 3 * 3), down + ((up - down) / 3 * 1), down + ((up - down) / 3 * 2));
		solve(left + ((right - left) / 3 * 2), left + ((right - left) / 3 * 3), down + ((up - down) / 3 * 2), down + ((up - down) / 3 * 3));
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &field[i][j]);
		}
	}
	solve(0, N, 0, N);
	for (int i = 0; i < 3; i++) {
		printf("%d\n", answer[i]);
	}
} 