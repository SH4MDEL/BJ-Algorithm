#include <iostream>
#include <string>
#include <unordered_map>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
int num[100100];
int counter[1000100];

int main()
{
	fastip; sws;
	cin >> n;
	int maximum = -inf;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
		counter[num[i]] = counter[num[i] - 1] + 1;
		maximum = max(counter[num[i]], maximum);
	}
	cout << maximum;
}