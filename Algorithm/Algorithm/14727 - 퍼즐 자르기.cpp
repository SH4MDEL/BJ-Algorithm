#include <iostream>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

long long num[1100000];
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
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	cout << solve(0, N - 1) << endl;
}