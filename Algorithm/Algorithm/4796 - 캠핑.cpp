#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int L, P, V;
int sum, casenum;

int main()
{
	scanf("%d %d %d", &L, &P, &V);
	casenum = 0;
	while (L != 0 || P != 0 || V != 0) {
		casenum++;
		sum = 0;
		while (1) {
			if (V - P >= 0) {
				V -= P;
				sum += L;
			}
			else {
				if (L >= V) {
					sum += V;
				}
				else {
					sum += L;
				}
				printf("Case %d: %d\n", casenum, sum);
				break;
			}
		}
		scanf("%d %d %d", &L, &P, &V);
	}
}