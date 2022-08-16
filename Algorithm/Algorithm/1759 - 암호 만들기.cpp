#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

int l, c;
vector<char> password;

void Search(int depth, int now, string s)
{
	if (s.size() == l) {
		int mo = 0, ja = 0;
		for (const auto& elm : s) {
			if (elm == 'a' || elm == 'e' || elm == 'i' || elm == 'o' || elm == 'u') {
				++mo;
				continue;
			}
			++ja;
		}
		if (mo >= 1 && ja >= 2) cout << s << endl;
		return;
	}
	for (int i = now + 1; i < c; ++i) {
		Search(depth + 1, i, s + password[i]);
	}

}

int main()
{
	cin >> l >> c;
	password.resize(c);
	for (int i = 0; i < c; ++i) {
		cin >> password[i];
	}
	sort(password.begin(), password.end());
	Search(0, -1, "");
}