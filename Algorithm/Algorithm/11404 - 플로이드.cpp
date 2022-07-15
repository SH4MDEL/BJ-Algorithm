#include <iostream>
#define endl "\n"
#define inf 987'654'321
using namespace std;

int graph[105][105];
int n, m;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i != j) {
				graph[i][j] = inf;
			}
		}
	}
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		if (graph[a][b] > c) {
			graph[a][b] = c;
		}
	}
	for (int m = 1; m <= n; ++m) {
		for (int s = 1; s <= n; ++s) {
			for (int e = 1; e <= n; ++e) {
				if (graph[s][e] > graph[s][m] + graph[m][e]) {
					graph[s][e] = graph[s][m] + graph[m][e];
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (graph[i][j] >= inf) {
				cout << "0 ";
			}
			else {
				cout << graph[i][j] << " ";
			}
		}
		cout << endl;
	}
}