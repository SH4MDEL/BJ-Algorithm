#include <iostream>
#include <string>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

string name, ach;
double credit, creditSum, achSum;

int main()
{
	sws; fastip;

	creditSum = 0.0;
	achSum = 0.0;

	for (int i = 0; i < 20; ++i) {
		cin >> name >> credit >> ach;

		if (ach == "A+") {
			achSum += 4.5 * credit;
			creditSum += credit;
			continue;
		}
		if (ach == "A0") {
			achSum += 4.0 * credit;
			creditSum += credit;
			continue;
		}
		if (ach == "B+") {
			achSum += 3.5 * credit;
			creditSum += credit;
			continue;
		}
		if (ach == "B0") {
			achSum += 3.0 * credit;
			creditSum += credit;
			continue;
		}
		if (ach == "C+") {
			achSum += 2.5 * credit;
			creditSum += credit;
			continue;
		}
		if (ach == "C0") {
			achSum += 2.0 * credit;
			creditSum += credit;
			continue;
		}
		if (ach == "D+") {
			achSum += 1.5 * credit;
			creditSum += credit;
			continue;
		}
		if (ach == "D0") {
			achSum += 1.0 * credit;
			creditSum += credit;
			continue;
		}
		if (ach == "F") {
			creditSum += credit;
			continue;
		}
		if (ach == "P") {
			continue;
		}
	}

	cout << achSum / creditSum;
}