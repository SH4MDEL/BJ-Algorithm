#include <iostream>
#include <vector>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int graph[101][101];
int n, m;

int main()
{
	fastip; sws;
	memset(graph, 10000, sizeof(int) * 101 * 101);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	for (int m = 1; m <= n; ++m) {
		for (int s = 1; s <= n; ++s) {
			for (int e = 1; e <= n; ++e) {
				graph[s][e] = min(graph[s][e], graph[s][m] + graph[m][e]);
			}
		}
	}

	int minimum = inf;
	int num = -1;
	for (int i = 1; i <= n; ++i) {
		int sum = 0;
		for (int j = 1; j <= n; ++j) {
			sum += graph[i][j];
		}
		if (sum < minimum) {
			minimum = sum;
			num = i;
		}
	}
	cout << num << endl;
}