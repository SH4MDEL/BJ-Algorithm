#include <iostream>
#include <string>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

struct mbti {
	mbti(string s)
	{
		i = 0;
		if (s[0] == 'E') i |= 0b1;
		if (s[1] == 'S') i |= 0b10;
		if (s[2] == 'T') i |= 0b100;
		if (s[3] == 'J') i |= 0b1000;
	}

	int operator-(const mbti& rhs) {
		int ans = 0;
		if ((0b1 & i) != (0b1 & rhs.i)) ++ans;
		if ((0b10 & i) != (0b10 & rhs.i)) ++ans;
		if ((0b100 & i) != (0b100 & rhs.i)) ++ans;
		if ((0b1000 & i) != (0b1000 & rhs.i)) ++ans;
		return ans;
	}
	int i;
};

int t, n;

int main()
{
	fastip; sws;

	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n;
		vector<mbti> v;
		for (int j = 0; j < n; ++j) {
			string s;
			cin >> s;
			v.push_back(mbti(s));
		}


		if (n >= 33) cout << 0 << endl;
		else {
			int minimum = inf;
			for (int a = 0; a < n; ++a) {
				for (int b = a + 1; b < n; ++b) {
					for (int c = b + 1; c < n; ++c) {
						minimum = min(minimum, ((v[a] - v[b]) + (v[b] - v[c]) + (v[a] - v[c])));
					}
				}
			}
			cout << minimum << endl;
		}
	}
}