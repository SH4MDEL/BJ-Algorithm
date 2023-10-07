#include <iostream>
#include <algorithm>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
vector<int> rope;

int main()
{
	fastip; sws;

	cin >> n;
	rope.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> rope[i];
	}
	sort(rope.begin(), rope.end(), [](const int& a, const int& b) {
		return a > b;
		});
	int maxNum = -inf;
	for (int i = 0; i < n; ++i) {
		maxNum = max(rope[i] * (i + 1), maxNum);
	}
	cout << maxNum;
}