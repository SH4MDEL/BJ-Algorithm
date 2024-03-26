#include <iostream>
#include <algorithm>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
int num[100100][3];
int cache[2][3];

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i][0] >> num[i][1] >> num[i][2];
	}
	cache[0][0] = num[n - 1][0]; 
	cache[0][1] = num[n - 1][1]; 
	cache[0][2] = num[n - 1][2];
	for (int i = n - 2; i >= 0; --i) {
		cache[1][0] = num[i][0] + max(cache[0][0], cache[0][1]);
		cache[1][1] = num[i][1] + max({ cache[0][0], cache[0][1], cache[0][2] });
		cache[1][2] = num[i][2] + max(cache[0][1], cache[0][2]);
		memcpy(cache[0], cache[1], sizeof(int) * 3);
	}
	cout << max({ cache[0][0], cache[0][1], cache[0][2] }) << " ";

	cache[0][0] = num[n - 1][0];
	cache[0][1] = num[n - 1][1];
	cache[0][2] = num[n - 1][2];
	for (int i = n - 2; i >= 0; --i) {
		cache[1][0] = num[i][0] + min(cache[0][0], cache[0][1]);
		cache[1][1] = num[i][1] + min({ cache[0][0], cache[0][1], cache[0][2] });
		cache[1][2] = num[i][2] + min(cache[0][1], cache[0][2]);
		memcpy(cache[0], cache[1], sizeof(int) * 3);
	}
	cout << min({ cache[0][0], cache[0][1], cache[0][2] }) << " ";
}