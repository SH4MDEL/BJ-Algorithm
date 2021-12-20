#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

bool num[1100];
int qnum;
int input, strike, ball;
int scount, bcount;
int possible;

int main()
{
	for (int i = 111; i < 1000; i++) {
		num[i] = true;
	}
	scanf("%d", &qnum);
	for (int i = 0; i < qnum; i++) {
		scanf("%d %d %d", &input, &strike, &ball);
		for (int j = 111; j < 1000; j++) {
			if ((j % 100) % 10 == 0 || (j % 100) / 10 == 0 || (j / 100) == 0) {
				num[j] = false;
				continue;
			}
			if ((j % 100) % 10 == (j % 100) / 10 || (j % 100) % 10 == (j / 100) || (j % 100) / 10 == (j / 100)) {
				num[j] = false;
				continue;
			}
			scount = 0;
			bcount = 0;
			if ((j % 100) % 10 == ((input % 100) % 10)) {
				scount++;
			}
			else if ((j % 100) / 10 == ((input % 100) % 10)) {
				bcount++;
			}
			else if ((j / 100) == ((input % 100) % 10)) {
				bcount++;
			}

			if ((j % 100) % 10 == ((input % 100) / 10)) {
				bcount++;
			}
			else if ((j % 100) / 10 == ((input % 100) / 10)) {
				scount++;
			}
			else if ((j / 100) == ((input % 100) / 10)) {
				bcount++;
			}

			if ((j % 100) % 10 == (input / 100)) {
				bcount++;
			}
			else if ((j % 100) / 10 == (input / 100)) {
				bcount++;
			}
			else if ((j / 100) == (input / 100)) {
				scount++;
			}

			if (scount != strike || bcount != ball) {
				num[j] = false;
			}
		}
	}
	possible = 0;
	for (int i = 111; i < 1000; i++) {
		if (num[i]) {
			possible++;
		}
	}
	printf("%d", possible);
}