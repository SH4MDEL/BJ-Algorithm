#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, s;
vector<int> v;

int search(int now, int c)
{
	if (c == n) return 0;
	
	int num = now + v[c];
	if (num == s) {
		return search(now, c + 1) + search(num, c + 1) + 1;
	}
	return search(now, c + 1) + search(num, c + 1);
}

int main()
{
	sws; fastip;

	cin >> n >> s;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << search(0, 0);
	
}