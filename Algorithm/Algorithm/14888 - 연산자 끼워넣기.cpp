#include <iostream>
#include <string>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 1987654321 
#define endl "\n"
using namespace std;

int n;
int num[15];
int op[4];
int minimum = inf, maximum = -inf;

void search(int depth, int plus, int minus, int mul, int div, int now)
{
	if (depth == n) {
		maximum = max(maximum, now);
		minimum = min(minimum, now);
		return;
	}
	if (plus != 0) search(depth + 1, plus - 1, minus, mul, div, now + num[depth]);
	if (minus != 0) search(depth + 1, plus, minus - 1, mul, div, now - num[depth]);
	if (mul != 0) search(depth + 1, plus, minus, mul - 1, div, now * num[depth]);
	if (div != 0) search(depth + 1, plus, minus, mul, div - 1, now / num[depth]);
}

int main()
{
	fastip; sws;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; ++i) {
		cin >> op[i];
	}
	search(1, op[0], op[1], op[2], op[3], num[0]);
	cout << maximum << endl << minimum;
}