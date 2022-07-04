#include <iostream>
#include <string>
#include <map>
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;

map<int, string> intmap;
map<string, int> stringmap;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n >> m;
	string inputstring;
	for (int i = 1; i <= n; ++i) {
		cin >> inputstring;
		stringmap[inputstring] = i;
		intmap[i] = inputstring;
	}
	for (int i = 0; i < m; ++i) {
		cin >> inputstring;
		if (inputstring[0] >= 48 && inputstring[0] <= 57) {
			cout << intmap[stoi(inputstring)] << endl;
		}
		else {
			cout << stringmap[inputstring] << endl;
		}
	}
}