#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int n, s;
int arr[25];

int find(int depth, int sum)
{
	if (depth == n) return 0;

	if (sum + arr[depth] == s) {
		return 1 + find(depth + 1, sum + arr[depth]) + find(depth + 1, sum);
	}
	return find(depth + 1, sum + arr[depth]) + find(depth + 1, sum);
}

int main()
{
	fastip; sws;

	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << find(0, 0);
}