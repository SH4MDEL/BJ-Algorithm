#include <iostream>
#define endl "\n"
using namespace std;

long long A, B;
int Min = 2'100'000'000;

void answer(long long number, int depth)
{
	if (number > B) {
		return;
	}
	if (number == B) {
		if (Min >= depth) {
			Min = depth;
		}
		return;
	}
	answer(number * 2, depth + 1);
	answer(number * 10 + 1, depth + 1);
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> A >> B;
	answer(A, 1);
	if (Min == 2'100'000'000) {
		cout << "-1" << endl;
	}
	else {
		cout << Min << endl;
	}
}