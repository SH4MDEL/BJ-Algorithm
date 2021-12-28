#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

long long A, B, C;

long long solve(long long A, long long B)
{
	if (B == 1) {
		return A % C;
	}
	else if (B == 2) {
		return (A % C * A % C) % C;
	}
	else {
		if (B % 2 == 0) {
			return (solve(A, B / 2) % C * solve(A, B / 2) % C) % C;
		}
		else {
			return (solve(A, B / 2) % C * solve(A, B / 2) % C * A % C) % C;
		}
	}
}

int main()
{
	scanf("%lld %lld %lld", &A, &B, &C);
	printf("%lld", solve(A, B));
}