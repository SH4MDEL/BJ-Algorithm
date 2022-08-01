#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#define endl "\n"
#define inf 987654321
using namespace std;

int main()
{
	unordered_set<string> us;
	string str;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		us.insert(str);
	}
	int count = 0;
	for (int i = 0; i < m; ++i) {
		cin >> str;
		if (us.find(str) != us.end()) {
			++count;
		}
	}
	cout << count << endl;
}