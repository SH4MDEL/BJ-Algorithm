#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

struct prob
{
	int d, v;

	bool operator<(const prob& rhs) const {
		return d < rhs.d;
	}
};
vector<prob> v;
int t, p;

int main()
{
	fastip; sws;

	v.resize(11);
	for (int i = 0; i < 11; ++i) {
		cin >> v[i].d >> v[i].v;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < 11; ++i) {
		t += v[i].d;
		p += t + v[i].v * 20;
	}
	cout << p;
}