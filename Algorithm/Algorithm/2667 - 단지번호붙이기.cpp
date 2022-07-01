#include <iostream>
#include <vector>
#include <algorithm>
#define inf 987654321 
#define endl "\n"
using namespace std;

char table[27][27];
int n;

vector<int> counter;

void Search(vector<int>::reverse_iterator now, int x, int y)
{
	if (table[y][x] != '1') {
		return;
	}
	table[y][x] = '2';
	*now += 1;
	Search(now, x - 1, y);
	Search(now, x + 1, y);
	Search(now, x, y - 1);
	Search(now, x, y + 1);
}

void AllSearch()
{
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (table[i][j] == '1') {
				counter.push_back(0);
				Search(counter.rbegin(), j, i);
			}
		}
	}
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	for (int i = 0; i < 27; ++i) {
		for (int j = 0; j < 27; ++j) {
			table[i][j] = '0';
		}
	}

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> table[i][j];
		}
	}
	AllSearch();
	cout << counter.size();
	sort(counter.begin(), counter.end());
	cout << endl;
	for (const auto& elm : counter) {
		cout << elm << endl;
	}
}