#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define ll long long
#define endl "\n"
using namespace std;

int n, k;

// 물병은 반드시 2^n 꼴로 담긴다.
// k는, n을 나눠 2^n 꼴의 숫자 몇 개를 확보할 수 있는지 묻고 있다.

int main()
{
	fastip; sws;

	cin >> n >> k;
	int tmp = n;
	int counter = 0;
	while (tmp) {
		if (tmp % 2) {
			++counter;
		}
		tmp /= 2;
	}
	if (counter <= k) {
		cout << 0;
		return 0;
	}
	counter = 0;
	int i = 30;
	for (; i >= 0; --i) {
		if (n & (1 << i)) {
			if (counter + 1 == k) break;
			n &= ~(1 << i);
			++counter;
		}
	}
	cout << (1 << (i + 1)) - n;
}