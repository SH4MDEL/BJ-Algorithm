#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

vector<int> v;

int main()
{
	fastip; sws;

	string s;
	cin >> s;
	
	string tmp;
	int sum = 0, sub = 0;
	bool isMinus = false;

	for (auto& c : s) {
		if (c == '-') {
			sub += stoi(tmp);
			tmp.clear();
			if (isMinus) v.push_back(-sub);
			else v.push_back(sub);
			sub = 0;
			isMinus = true;
		}
		else if (c == '+') {
			sub += stoi(tmp);
			tmp.clear();
		}
		else tmp.push_back(c);
	}
	sub += stoi(tmp);
	tmp.clear();
	if (isMinus) v.push_back(-sub);
	else v.push_back(sub);
	sub = 0;
	isMinus = true;

	cout << accumulate(v.begin(), v.end(), 0);
}