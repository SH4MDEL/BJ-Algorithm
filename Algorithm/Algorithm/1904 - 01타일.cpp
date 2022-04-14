#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
int N;
long long cache[1100000];

int main()
{
	scanf("%d", &N);
	cache[1] = 1;
	cache[2] = 1;
	for (int i = 3; i <= N + 1; ++i) {
		cache[i] = (cache[i - 1] % 15746 + cache[i - 2] % 15746) % 15746;
	}
	printf("%lld", cache[N + 1] % 15746);
}