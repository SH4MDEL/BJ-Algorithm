#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

long long num[110000];
int N;

long long solve(long long start, long long end)
{
	if (start == end) {
		return num[start];
	}
	long long mid = (start + end) / 2;
	long long result = std::max(solve(start, mid), solve(mid + 1, end));
	long long lo = mid, high = mid, height = std::min(num[lo], num[high]);
	long long right, left;
	while (lo > start || high < end) {
		right = -1, left = -1;
		if (high < end) {
			right = (high - lo + 2) * std::min(height, num[high + 1]);
		}
		if (lo > start) {
			left = (high - lo + 2) * std::min(height, num[lo - 1]);
		}
		if (right >= left) {
			high++;
			height = std::min(height, num[high]);
			result = std::max(right, result);
		}
		else {
			lo--;
			height = std::min(height, num[lo]);
			result = std::max(left, result);
		}
	}
	return result;
}

int main()
{
	while (1) {
		scanf("%d", &N);
		if (N == 0) {
			break;
		}
		for (int i = 0; i < N; i++) {
			scanf("%lld", &num[i]);
		}
		printf("%lld\n", solve(0, N - 1));
	}
}