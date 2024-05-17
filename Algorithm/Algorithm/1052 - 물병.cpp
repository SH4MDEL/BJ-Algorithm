#include <iostream>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define ll long long
#define endl "\n"
using namespace std;

int n, k;

// ������ �ݵ�� 2^n �÷� ����.
// k��, n�� ���� 2^n ���� ���� �� ���� Ȯ���� �� �ִ��� ���� �ִ�.

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