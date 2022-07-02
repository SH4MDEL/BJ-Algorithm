#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
string inputnum;

vector<string> numlist;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> inputnum;
		numlist.push_back(inputnum);
	}
	sort(numlist.begin(), numlist.end(), [](string a, string b) {
		return a > b;
		});
	for (auto i = numlist.rbegin(); i < numlist.rend() - 1; ++i) {
		if (*i + *(i + 1) > *(i + 1) + *i) {
			auto tmp = *i;
			*i = *(i + 1);
			*(i + 1) = tmp;
		}
	}
	if (numlist[0][0] == '0') {
		cout << "0" << endl;
	}
	else {
		for (const auto& elm : numlist) {
			cout << elm;
		}
	}
	cout << endl;

}