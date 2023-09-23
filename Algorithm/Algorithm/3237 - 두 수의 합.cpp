#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, x, counter;
vector<int> v;

int main()
{
	fastip; sws;

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	cin >> x;
	sort(v.begin(), v.end());
	auto a = v.begin();
	auto b = v.end() - 1;
	while (a < b) {
		if (*a + *b == x) {
			++counter;
			++a;
		}
		else if (*a + *b > x) {
			--b;
		}
		else {
			++a;
		}
	}
	cout << counter;
}