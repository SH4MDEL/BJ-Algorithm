#include <iostream>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 1087654321 
#define endl "\n"
using namespace std;

int arr[1010];
int cache[1010];
int n, maximum = -inf;

int main() {
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i) {
		int maxNum = 0;
		for (int j = 0; j < i; ++j) {
			if (arr[j] < arr[i]) {
				maxNum = max(maxNum, cache[j]);
			}
		}
		cache[i] = maxNum + arr[i];
		maximum = max(maximum, cache[i]);
	}
	cout << maximum;
}