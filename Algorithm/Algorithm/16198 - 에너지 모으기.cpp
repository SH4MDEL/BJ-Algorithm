#include <iostream>
#include <string>
#include <tuple>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
int num[15];

tuple<int, int> GetSideIndex(int deleted, int index)
{
	int left = -1, right = -1;
	for (int i = index - 1; i >= 0; --i) {
		if (!(deleted & (1 << i))) {
			left = i;
			break;
		}
	}
	for (int i = index + 1; i < n; ++i) {
		if (!(deleted & (1 << i))) {
			right = i;
			break;
		}
	}

	return { left, right };
}

int search(int deleted, int depth)
{
	if (depth == n - 2) return 0;

	int maximum = -inf;
	for (int i = 0; i < n; ++i) {
		if (deleted & (1 << i)) continue;
		auto [left, right] = GetSideIndex(deleted, i);
		if (left == -1 || right == -1) continue;

		maximum = max(maximum, 
			search((deleted | (1 << i)), depth + 1) + num[left] * num[right]);
	}
	return maximum;
}

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	cout << search(0, 0);
}