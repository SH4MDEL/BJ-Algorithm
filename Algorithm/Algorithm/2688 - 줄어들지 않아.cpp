#include <iostream>
#include <string>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

int t, n;
ll cache[70][10];

int main()
{
	fastip; sws;
	for (int i = 0; i < 10; ++i) {
		cache[0][i] = 1LL;
	}
	for (int i = 1; i <= 65; ++i) {
		for (int j = 0; j <= 9; ++j) {
			for (int k = j; k <= 9; ++k) {
				cache[i][j] += cache[i - 1][k];
			}
		}
	}
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n;
		cout << cache[n][0] << endl;
	}
}