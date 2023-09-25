#include <iostream>
#include <stack>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
stack<pair<int, int>> s;

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int height;
		cin >> height;
		[&]() {
			while (!s.empty()) {
				auto now = s.top();
				if (now.first > height) {
					cout << now.second << " ";
					return;
				}
				else {
					s.pop();
				}
			}
			cout << "0 ";
		}();
		s.push({ height, i });
	}
}