#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int list[50];
int tCase;
int inputnum;

int answer(int input)
{
	for (int i = 1; i < 50; i++) {
		for (int j = 1; j < 50; j++) {
			for (int k = 1; k < 50; k++) {
				if (input == list[i] + list[j] + list[k]) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	for (int i = 1; i < 50; i++) {
		list[i] = i * (i + 1) / 2;
	}
	scanf("%d", &tCase);
	for (int i = 0; i < tCase; i++) {
		scanf("%d", &inputnum);
		printf("%d\n", answer(inputnum));
	}
}