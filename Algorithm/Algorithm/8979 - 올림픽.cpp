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

struct Country {
	int gold;
	int silver;
	int bronze;
	int num;

	bool operator< (const Country& c) {
		if (gold == c.gold) {
			if (silver == c.silver) {
				return bronze > c.bronze;
			}
			return silver > c.silver;
		}
		return gold > c.gold;
	}
	bool operator == (const Country& c) {
		return gold == c.gold and silver == c.silver and bronze == c.bronze;
	}
};
vector<Country> v;
int n, m;

int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int num, g, s, b;
		cin >> num >> g >> s >> b;
		v.emplace_back(g, s, b, num);
	}
	sort(v.begin(), v.end());

	Country prevC{-1, -1, -1, 0};
	int prevR = 1;
	for (int i = 0; const auto & e : v) {
		++i;
		if (prevC != e) {
			prevC = e;
			prevR = i;
		}
		if (e.num == m) {
			cout << prevR << endl;
			break;
		}
	}
}