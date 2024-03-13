#include <iostream>
#include <unordered_set>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int num[100100];
int field[1000100];
unordered_set<int> have;
int n;

void check(int n)
{
	if (have.count(1)) {
		--field[n]; ++field[1];
	}

	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			if (have.count(i)) {
				--field[n]; ++field[i];
			}
			int k = n / i;
			if (i == k) continue;
			if (have.count(k)) {
				--field[n]; ++field[k];
			}
		}
	}
}

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
		have.insert(num[i]);
	}

	for (int i = 0; i < n; ++i) {
		check(num[i]);
	}

	for (int i = 0; i < n; ++i) {
		cout << field[num[i]] << " ";
	}
}