#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
vector<int> v;

int main()
{
	fastip; sws;

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int cut = floor((float)n * 0.15 + 0.5);
	v.erase(v.begin(), v.begin() + cut);
	v.erase(v.end() - cut, v.end());

	if (n) cout << (int)floor(accumulate(v.begin(), v.end(), 0.0) / ((float)n - 2.0 * (float)cut) + 0.5);
	else cout << 0;
}