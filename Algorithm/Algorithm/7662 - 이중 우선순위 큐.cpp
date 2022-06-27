#include <iostream>
#include <set>
#include <string>

std::multiset<int, std::greater<int>> set;

int testcase, datanum, inputnum;
std::string inputstr;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	std::cin >> testcase;
	for (int i = 0; i < testcase; ++i) {
		std::cin >> datanum;
		for (int j = 0; j < datanum; ++j) {
			std::cin >> inputstr >> inputnum;
			if (inputstr == "I") {
				set.insert(inputnum);
			}
			else if (inputstr == "D") {
				if (set.empty()) {

				}
				else if (inputnum == 1) {
					std::cout << *set.begin() << "삭제\n";
					set.erase(set.begin());
				}
				else if (inputnum == -1) {
					std::cout << *(--set.end()) << "삭제\n";
					set.erase(--set.end());
				}
			}
		}
		if (set.empty()) {
			std::cout << "EMPTY\n";
		}
		else {
			std::cout << *set.begin() <<  " " << *(--set.end()) << "\n";
		}
		set.erase(set.begin(), set.end());
	}
}