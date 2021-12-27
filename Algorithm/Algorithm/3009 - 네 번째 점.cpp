#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int coordinate[3][2];
int answer[2];

int main()
{
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &coordinate[i][0], &coordinate[i][1]);
		
	}
	if (coordinate[0][0] == coordinate[1][0]) {
		answer[0] = coordinate[2][0];
	}
	else if (coordinate[1][0] == coordinate[2][0]) {
		answer[0] = coordinate[0][0];
	}
	else {
		answer[0] = coordinate[1][0];
	}
	if (coordinate[0][1] == coordinate[1][1]) {
		answer[1] = coordinate[2][1];
	}
	else if (coordinate[1][1] == coordinate[2][1]) {
		answer[1] = coordinate[0][1];
	}
	else {
		answer[1] = coordinate[1][1];
	}
	printf("%d %d", answer[0], answer[1]);
}
