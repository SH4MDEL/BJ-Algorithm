#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

int N, L;
int num[1100];
int usedTapeNum, leastTape;

int main()
{
	usedTapeNum = 0, leastTape = 0;
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	std::sort(num, num + N);
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			leastTape = L - 1;
			usedTapeNum++;
		}
		else if (num[i] - num[i - 1] > leastTape) {
			leastTape = L - 1;
			usedTapeNum++;
		}
		else {
			leastTape -= num[i] - num[i - 1];
		}
	}
	printf("%d\n", usedTapeNum);
}