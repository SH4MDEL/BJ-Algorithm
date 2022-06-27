#include <iostream>
#define endl "\n"

int N, K;
int data[100];
int cache[101][10001];

int solve(int n, int k)
{
	if (cache[n][k] != -1) {
		return cache[n][k];
	}
	for (int i = data[n]; i < k; i + data[n]) {
		cache[n][i] = 1 + solve(n + 1, k - data[n]);
	}
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	std::cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		std::cin >> data[i];
	}
	std::cout << solve(0, K);
}