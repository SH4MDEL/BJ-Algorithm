#include <iostream>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

int num[1000100];
int n, m, ans;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	sort(num, num + n);

	int s = 0, e = num[n - 1];
	while (s + 1 < e) {
		int mid = (s + e) / 2;
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			if (num[i] > mid) {
				sum += num[i] - mid;
			}
		}
		if (sum >= m) {
			s = mid;
		}
		if (sum < m) {
			e = mid;
		}
	}
	cout << s << endl;
}