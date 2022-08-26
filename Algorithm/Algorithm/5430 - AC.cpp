#include <iostream>
#include <string>
#include <deque>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int t, n, num;
bool breverse, error;
deque<int> d;
string command;
char sdata;

int main()
{
	sws; fastip;

	cin >> t;
	for (int i = 0; i < t; ++i) {
		d.clear();
		for (const auto & elm : d) {
			cout << elm << endl;
		}
		error = false;
		breverse = false;
		cin >> command;
		cin >> n;
		if (n != 0) {
			for (int i = 0; i < n * 2 + 1; ++i) {
				if (i % 2 == 1) {
					cin >> num;
					d.push_back(num);
				}
				else {
					cin >> sdata;
				}
			}
		}
		else {
			cin >> sdata;
			cin >> sdata;
		}

		for (const auto & elm : command) {
			if (elm == 'R') {
				if (breverse) breverse = false;
				else breverse = true;
			}
			if (elm == 'D') {
				if (d.empty()) {
					cout << "error" << endl;
					error = true;
					break;
				}
				if (breverse) {
					d.pop_back();
					continue;
				}
				d.pop_front();
			}
		}
		if (!error) {
			cout << "[";
			if (!breverse) {
				for (int i = 0; i < d.size(); ++i) {
					cout << d[i];
					if (i != d.size() - 1) {
						cout << ",";
					}
				}
			}
			else {
				for (int i = d.size() - 1; i >= 0; --i) {
					cout << d[i];
					if (i != 0) {
						cout << ",";
					}
				}
			}
			cout << "]" << endl;
		}
	}
}