#include <iostream>
#include <vector>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int n, m;
bool visited[2020];
vector<int> children[2020];

bool make_tree(int parent, int me, int depth)
{
	if (depth == 4) return true;
	if (children[me].size() == 1 && parent != -1) return false;
	
	for (const auto& child : children[me]) {
		if (visited[child]) continue;
		visited[child] = true;
		if (make_tree(me, child, depth + 1)) {
			return true;
		}
		visited[child] = false;
	}
	return false;
}

int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		children[a].push_back(b);
		children[b].push_back(a);
	}
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		visited[i] = true;
		if (make_tree(-1, i, 0)) {
			ans = 1;
			break;
		}
		visited[i] = false;
	}
	cout << ans;
}