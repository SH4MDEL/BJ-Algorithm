#include <iostream>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int n;
int num[21];
bool can[2000200];

int main()
{
	fastip; sws;

	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
		sum += num[i];
	}

	for (int i = n; i >= 0; --i) {
		for (int j = sum; j >= 1; --j) {
			if (can[j]) can[j + num[i]] = true;
			if (num[i] == j) can[j] = true;
		}
	}

	for (int i = 1; i <= sum + 1; ++i) {
		if (!can[i]) {
			cout << i;
			break;
		}
	}
}