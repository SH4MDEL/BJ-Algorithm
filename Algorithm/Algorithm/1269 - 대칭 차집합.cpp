#include <iostream>
#include <unordered_set>
#define endl "\n"
#define inf 987654321
using namespace std;

int main()
{
	unordered_set<int> usa;
	unordered_set<int> usb;
	int num;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		usa.insert(num);
	}
	for (int i = 0; i < m; ++i) {
		cin >> num;
		usb.insert(num);
	}
	int count = 0;
	for (const auto& elm : usa) {
		if (usb.find(elm) == usb.end()) ++count;
	}
	for (const auto& elm : usb) {
		if (usa.find(elm) == usa.end()) ++count;
	}
	cout << count << endl;
}