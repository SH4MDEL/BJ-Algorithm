#include <iostream>
#include <string>
#include <unordered_map>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;
unordered_map<string, string> um;

int main()
{
	fastip; sws;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string a, b;
		cin >> a >> b;
		um[a] = b;
	}
	for (int i = 0; i < m; ++i) {
		string a;
		cin >> a;
		cout << um[a] << endl;
	}
}