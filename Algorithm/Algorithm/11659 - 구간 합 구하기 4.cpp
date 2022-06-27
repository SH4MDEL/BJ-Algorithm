#include <iostream>
#define endl "\n"
using namespace std;

int origin[110000];
int table[110000];
int N, M;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> N >> M;
	table[0] = 0;
	for (int i = 1; i <= N; ++i) {
		cin >> origin[i];
		table[i] = table[i - 1] + origin[i];
	}
	int I, J;
	for (int i = 0; i < M; ++i) {
		cin >> I >> J;
		cout << table[J] - table[I - 1] << endl;
	}
}