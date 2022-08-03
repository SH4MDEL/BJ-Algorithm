#include <iostream>
#define endl "\n"
#define inf 987654321
using namespace std;

int iptnum, maxnum, nownum;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	int n;
	maxnum = -inf;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> iptnum;
		nownum += iptnum;
		if (nownum > maxnum) maxnum = nownum;
		if (nownum < 0) nownum = 0;
	}
	cout << maxnum << endl;
}