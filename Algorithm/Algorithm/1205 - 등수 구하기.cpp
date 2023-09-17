#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, score, p;
vector<int> v;

int main()
{
	fastip; sws;

	cin >> n >> score >> p;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	if (n == p && *v.rbegin() >= score) {
		cout << -1;
	}
	else if (n == 0) {
		cout << 1;
	}
	else {
		int i = 0;
		for (const auto & e : v) {
			++i;
			if (score >= e) {
				cout << i;
				break;
			}
		}
		if (*v.rbegin() > score) {
			cout << n + 1 << endl;
		}
	}

}