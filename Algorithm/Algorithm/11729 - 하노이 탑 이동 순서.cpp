#include <iostream>
#include <vector>
#include <stack>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int n;
vector<pair<int, int>> ans;
void solve(int n, int s, int e)
{
	if (!n) return;

	int v = 3 - s - e;
	solve(n - 1, s, v);
	ans.push_back({s, e});
	solve(n - 1, v, e);
}


int main()
{
	fastip; sws;

	cin >> n;
	solve(n, 0, 2);
	cout << ans.size() << endl;
	for (auto [from, to] : ans) {
		cout << from + 1 << " " << to + 1 << endl;
	}
}