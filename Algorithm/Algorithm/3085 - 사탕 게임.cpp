#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

char board[50][50];
int maxcandy = 0;
int longestString = 0;
char nowColor = 0;
int N;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", board[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (board[i][j] != board[i][j + 1]) {
				board[i][j] += board[i][j + 1];
				board[i][j + 1] = board[i][j] - board[i][j + 1];
				board[i][j] -= board[i][j + 1];
				for (int k = 0; k < N; k++) {
					for (int l = 0; l < N; l++) {
						if (board[k][l] == nowColor) {
							longestString++;
							if (longestString > maxcandy) {
								maxcandy = longestString;
							}
						}
						else {
							nowColor = board[k][l];
							longestString = 1;
						}
					}
					nowColor = 0;
					longestString = 1;
				}
				for (int l = 0; l < N; l++) {
					for (int k = 0; k < N; k++) {
						if (board[k][l] == nowColor) {
							longestString++;
							if (longestString > maxcandy) {
								maxcandy = longestString;
							}
						}
						else {
							nowColor = board[k][l];
							longestString = 1;
						}
					}
					nowColor = 0;
					longestString = 1;
				}
				board[i][j] += board[i][j + 1];
				board[i][j + 1] = board[i][j] - board[i][j + 1];
				board[i][j] -= board[i][j + 1];
			}
		}
	}
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {
			if (board[i][j] != board[i + 1][j]) {
				board[i][j] += board[i + 1][j];
				board[i + 1][j] = board[i][j] - board[i + 1][j];
				board[i][j] -= board[i + 1][j];
				for (int k = 0; k < N; k++) {
					for (int l = 0; l < N; l++) {
						if (board[k][l] == nowColor) {
							longestString++;
							if (longestString > maxcandy) {
								maxcandy = longestString;
							}
						}
						else {
							nowColor = board[k][l];
							longestString = 1;
						}
					}
					nowColor = 0;
					longestString = 1;
				}
				for (int l = 0; l < N; l++) {
					for (int k = 0; k < N; k++) {
						if (board[k][l] == nowColor) {
							longestString++;
							if (longestString > maxcandy) {
								maxcandy = longestString;
							}
						}
						else {
							nowColor = board[k][l];
							longestString = 1;
						}
					}
					nowColor = 0;
					longestString = 1;
				}
				board[i][j] += board[i + 1][j];
				board[i + 1][j] = board[i][j] - board[i + 1][j];
				board[i][j] -= board[i + 1][j];
			}
		}
	}
	for (int k = 0; k < N; k++) {
		for (int l = 0; l < N; l++) {
			if (board[k][l] == nowColor) {
				longestString++;
				if (longestString > maxcandy) {
					maxcandy = longestString;
				}
			}
			else {
				nowColor = board[k][l];
				longestString = 1;
			}
		}
		nowColor = 0;
		longestString = 1;
	}
	for (int l = 0; l < N; l++) {
		for (int k = 0; k < N; k++) {
			if (board[k][l] == nowColor) {
				longestString++;
				if (longestString > maxcandy) {
					maxcandy = longestString;
				}
			}
			else {
				nowColor = board[k][l];
				longestString = 1;
			}
		}
		nowColor = 0;
		longestString = 1;
	}
	printf("%d\n", maxcandy);
}