#include <iostream>
#define endl "\n"
#define inf 987654321

int N, K;
int data[111];
int cache[111111];

int solve(int k)
{
	if (k < 0) {
		return inf;
	}
	if (cache[k] != -1) {
		return cache[k];
	}
	int min = inf;
	for (int i = 0; i < N; ++i) {
		if (min > solve(k - data[i]) + 1) {
			min = solve(k - data[i]) + 1;
		}
	}
	return cache[k] = min;

}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	for (int i = 0; i < 110000; ++i) {
		cache[i] = -1;
	}

	std::cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		std::cin >> data[i];
		cache[data[i]] = 1;
	}
	if (solve(K) == inf) {
		std::cout << -1 << endl;
	}
	else {
		std::cout << solve(K);
	}
}