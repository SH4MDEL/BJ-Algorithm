#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int tc, ans;

int main()
{
	fastip; sws;

	cin >> tc;
	for (int i = 0; i < tc; ++i) {
		ans = 0;
		vector<int> students(20);
		vector<int> line;

		int n;
		cin >> n;

		for (int j = 0; j < 20; ++j) {
			cin >> students[j];
		}
		for (const auto& student : students) {
			bool run = false;
			for (auto itr = line.begin(); itr != line.end(); ++itr) {
				if (*itr > student) {
					ans += distance(itr, line.end());
					line.insert(itr, student);
					run = true;
					break;
				}
			}
			if (!run) {
				line.push_back(student);
			}
		}
		cout << n << " " << ans << endl;
	}
}