#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>

long long T, start, end;

long long solve(long long dist)
{
	if (dist == 0) {
		return 1;
	}
	else if (dist == 1) {
		return 2;
	}
	else if (dist == 2 || dist == 3) {
		return 3;
	}
	long long base = (long long)sqrt(dist);
	long long weight = (base + 1) * (base + 1) - base * base;
	if (dist - (base * base) < weight / 2) {
		return base * 2;
	}
	else {
		return base * 2 + 1;
	}

}

int main()
{
	scanf("%lld", &T);
	for (int i = 0; i < T; i++) {
		scanf("%lld %lld", &start, &end);
		printf("%lld\n", solve(end - start - 1));
	}
}