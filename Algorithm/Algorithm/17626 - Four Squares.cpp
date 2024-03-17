#include <iostream>
#include <optional>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
vector cache(70000, optional<int>());

int main()
{
	fastip; sws;
	cin >> n;
	for (int i = 1; i <= 250; ++i) {
		cache[i * i].emplace(1);
	}
	for (int i = 1; i <= 250; ++i) {
		for (int j = 1; j <= 250; ++j) {
			int next = i * i + j * j;
			if (next > 50000) break;
			if (!cache[next].has_value()) {
				cache[next].emplace(2);
			}
		}
	}
	for (int i = 1; i <= 250; ++i) {
		for (int j = 1; j <= 250; ++j) {
			for (int k = 1; k <= 250; ++k) {
				int next = i * i + j * j + k * k;
				if (next > 50000) break;
				if (!cache[next].has_value()) {
					cache[next].emplace(3);
				}
			}
		}
	}
	if (cache[n].has_value()) {
		cout << cache[n].value();
	}
	else cout << 4;
}