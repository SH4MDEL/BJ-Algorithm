#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
int N;
long long cache[100];

long long solve(int level)
{
	if (level == 1 || level == 2) {
		return 1;
	}
	if (cache[level] != -1) {
		return cache[level];
	}
	else {
		return cache[level] = solve(level - 1) + solve(level - 2);
	}
}
int main()
{
	for (int i = 0; i < 100; ++i) {
		cache[i] = -1;
	}
	scanf("%d", &N);
	printf("%lld", solve(N));
}