#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#define endl "\n"
using namespace std;

int N, M;
set<string> 듣도못한사람;
set<string> 듣도보도못한사람;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	string input;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> input;
		듣도못한사람.insert(input);
	}
	for (int i = 0; i < M; ++i) {
		cin >> input;
		if (듣도못한사람.find(input) != 듣도못한사람.end()) {
			듣도보도못한사람.insert(input);
		}
	}
	cout << 듣도보도못한사람.size() << endl;
	for (const auto& elm : 듣도보도못한사람) {
		cout << elm << endl;
	}
}