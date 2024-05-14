#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define mod 1000000
#define ll long long
#define endl "\n"
using namespace std;

int n;

bool isPrime(int num)
{
	if (num == 0 || num == 1) return false;
	for (int i = 2; i * i <= num; ++i) {
		if (!(num % i)) return false;
	}
	return true;
}

void search(int num, int depth)
{
	if (!isPrime(num)) return;
	if (depth == n) {
		cout << num << endl;
		return;
	}
	for (int i = 1; i <= 9; i += 2) {
		search(num * 10 + i, depth + 1);
	}
}

int main()
{
	fastip; sws;
	cin >> n;
	for (int i = 1; i <= 9; ++i) search(i, 1);
}