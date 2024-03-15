#include <iostream>
#include <memory>
#include <list>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int n, m;

struct Node;
int parents[17][100100];
shared_ptr<Node> nodes[100100];

struct Node {
	int index, depth;
	list<shared_ptr<Node>> adjacent;

	void SetParent(int d, int p)
	{
		depth = d;
		for (auto& adj : adjacent) {
			if (adj->index != p) {
				parents[0][adj->index] = index;
				adj->SetParent(d + 1, index);
			}
		}
	}
};

int main()
{
	fastip; sws;

	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		
		if (!nodes[a]) nodes[a] = make_shared<Node>();
		if (!nodes[b]) nodes[b] = make_shared<Node>();
		nodes[a]->index = a;
		nodes[a]->adjacent.push_back(nodes[b]);
		nodes[b]->index = b;
		nodes[b]->adjacent.push_back(nodes[a]);
	}
	nodes[1]->SetParent(0, 0);

	for (int i = 1; i < 17; ++i) {
		if ((1 << i) > n) break;
		for (int j = 1; j <= n; ++j) {
			if (parents[i - 1][j] == 0) continue;
			parents[i][j] = parents[i - 1][parents[i - 1][j]];
		}
	}

	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		auto major = nodes[a];
		auto minor = nodes[b];

		if (major->depth < minor->depth) swap(major, minor);

		int def = major->depth - minor->depth;
		int count = 0;
		while (def) {
			if (def % 2) {
				major = nodes[parents[count][major->index]];
			}
			def /= 2;
			++count;
		}

		while (major != minor) {
			for (int i = 0; i < 16; ++i) {
				major = nodes[parents[i][major->index]];
				minor = nodes[parents[i][minor->index]];
				if (nodes[parents[i][major->index]] == nodes[parents[i][minor->index]]) break;
				if (nodes[parents[i + 1][major->index]] == nodes[parents[i + 1][minor->index]]) break;
			}
		}

		cout << major->index << endl;
	}
}