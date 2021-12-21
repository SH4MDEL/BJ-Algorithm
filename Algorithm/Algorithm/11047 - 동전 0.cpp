#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int N, K;
int value[15];
int minsum = 0, leastK = 0;

int main()
{
	scanf("%d %d", &N, &K);
	leastK = K;
	for (int i = N - 1; i >= 0; i--) {
		scanf("%d", &value[i]);
	}
	for (int i = 0; i < N; i++) {
		if (leastK % value[i] == 0 && leastK / value[i] == 0) {
			continue;
		}
		else {
			minsum += leastK / value[i];
			leastK %= value[i];
		}
	}
	printf("%d\n", minsum);
}