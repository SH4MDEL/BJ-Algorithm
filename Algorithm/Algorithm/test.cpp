#include <iostream>
#include <algorithm>
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, k, now, maximum, sum;
int num[100100];

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	for (int i = 0; i < k; ++i) {
		sum += num[i];
	}
	maximum = sum;
	for (int i = k; i < n; ++i) {
		sum += num[i];
		sum -= num[now];
		++now;
		maximum = max(maximum, sum);
	}
	cout << maximum << endl;
}