#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#define endl "\n"
using namespace std;

int N, M;
set<string> �赵���ѻ��;
set<string> �赵�������ѻ��;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	string input;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> input;
		�赵���ѻ��.insert(input);
	}
	for (int i = 0; i < M; ++i) {
		cin >> input;
		if (�赵���ѻ��.find(input) != �赵���ѻ��.end()) {
			�赵�������ѻ��.insert(input);
		}
	}
	cout << �赵�������ѻ��.size() << endl;
	for (const auto& elm : �赵�������ѻ��) {
		cout << elm << endl;
	}
}