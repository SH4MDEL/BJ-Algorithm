#include <iostream>
#include <string>
#include <deque>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int h, w, n, m;

int main()
{
	sws; fastip;
	cin >> h >> w >> n >> m;
	cout << (h / (n + 1) + (h % (n + 1) != 0 ? 1 : 0)) * (w / (m + 1) + (w % (m + 1) != 0 ? 1 : 0)) << endl;
}