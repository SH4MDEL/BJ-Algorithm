#include <iostream>
#include <string>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define ll long long
#define endl "\n"
using namespace std;

int gcd(int a, int b)
{
	int r = a % b;
	if (r == 0) return b;
	return gcd(b, r);
}

int n;
int arr[100100];

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int gap = gcd(arr[1] - arr[0], arr[2] - arr[1]);
	for (int i = 2; i < n - 1; ++i) {
		gap = gcd(gap, arr[i + 1] - arr[i]);
	}
	int ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		ans += (arr[i + 1] - arr[i]) / gap - 1;
	}
	cout << ans;
}