#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

const double PI = 3.14159265358979;
double R;

int main()
{
	scanf("%lf", &R);
	printf("%6f\n%6f", R * R * PI, R * R * 2.0);
}