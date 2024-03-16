#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int n, k;
int adj[100100];
int parent[18][100100];
int minimax[2][18][100100];
int root;
unordered_map<int, int> cost[100100];

struct Node;
shared_ptr<Node> nodes[100100];
struct Node {
	Node(int index) : index{ index } {}
	int index, depth;

	vector<shared_ptr<Node>> adjacent;

	void SetParent(int d, int p) {
		depth = d;
		if (p) {
			parent[0][index] = p;
			minimax[0][0][index] = cost[p][index];
			minimax[1][0][index] = cost[p][index];
		}
		for (auto& adj : adjacent) {
			if (adj == nodes[p]) continue;
			adj->SetParent(d + 1, index);
		}
	}
};

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		cost[a].insert({ b, c });
		cost[b].insert({ a, c });
		if (!nodes[a]) nodes[a] = make_shared<Node>(a);
		if (!nodes[b]) nodes[b] = make_shared<Node>(b);

		nodes[a]->adjacent.push_back(nodes[b]);
		nodes[b]->adjacent.push_back(nodes[a]);
	}
	for (int i = 0; i <= n; ++i) {
		minimax[0][0][i] = inf;
		minimax[1][0][i] = -inf;
	}

	nodes[1]->SetParent(0, 0);

	for (int i = 1; i <= 17; ++i) {
		if ((1 << i) > n) break;
		for (int j = 1; j <= n; ++j) {
			if (parent[i - 1][j] == 0) continue;
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
			minimax[0][i][j] = min(minimax[0][i - 1][j], minimax[0][i - 1][parent[i - 1][j]]);
			minimax[1][i][j] = max(minimax[1][i - 1][j], minimax[1][i - 1][parent[i - 1][j]]);
		}
	}

	cin >> k;
	for (int i = 0; i < k; ++i) {
		int a, b;
		cin >> a >> b;
		int minimum = inf;
		int maximum = -inf;

		auto major = nodes[a];
		auto minor = nodes[b];
		if (major->depth < minor->depth) swap(major, minor);

		int def = abs(major->depth - minor->depth);
		int count = 0;
		while (def) {
			if (def % 2) {
				minimum = min(minimum, minimax[0][count][major->index]);
				maximum = max(maximum, minimax[1][count][major->index]);
				major = nodes[parent[count][major->index]];
			}
			def /= 2;
			++count;
		}

		while (major != minor) {
			for (int i = 17; i >= 0; --i) {
				if (parent[i][major->index] == 0) continue;
				if (parent[i][major->index] != parent[i][minor->index]) {
					minimum = min(minimum, minimax[0][i][major->index]);
					maximum = max(maximum, minimax[1][i][major->index]);
					major = nodes[parent[i][major->index]];

					minimum = min(minimum, minimax[0][i][minor->index]);
					maximum = max(maximum, minimax[1][i][minor->index]);
					minor = nodes[parent[i][minor->index]];
				}
			}
			minimum = min(minimum, minimax[0][0][major->index]);
			maximum = max(maximum, minimax[1][0][major->index]);
			major = nodes[parent[0][major->index]];

			minimum = min(minimum, minimax[0][0][minor->index]);
			maximum = max(maximum, minimax[1][0][minor->index]);
			minor = nodes[parent[0][minor->index]];
		}

		cout << minimum << " " << maximum << endl;
	}
}