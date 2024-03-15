#include <iostream>
#include <memory>
#include <list>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

struct Node {
	int index, depth;
	shared_ptr<Node> parent;
	list<shared_ptr<Node>> children;

	void SetDepth(int start)
	{
		depth = start;
		for (auto& child : children) {
			child->SetDepth(depth + 1);
		}
	}
	void Clear()
	{
		children.clear();
		parent = nullptr;
	}
};
shared_ptr<Node> nodes[10101];

int t, n;


int main()
{
	fastip; sws;

	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n;
		for (int j = 0; j < n - 1; ++j) {
			int a, b;
			cin >> a >> b;
			if (!nodes[b]) nodes[b] = make_shared<Node>();
			nodes[b]->index = b;
			if (!nodes[a]) nodes[a] = make_shared<Node>();
			nodes[b]->parent = nodes[a];
			nodes[a]->children.push_back(nodes[b]);
		}
		int root;
		for (int i = 1; i <= n; ++i) {
			if (!nodes[i]->parent) {
				nodes[i]->index = i;
				root = i;
				break;
			}
		}
		nodes[root]->SetDepth(0);
		int a, b;
		cin >> a >> b;
		auto pa = nodes[a];
		auto pb = nodes[b];

		while (pa->depth != pb->depth) {
			if (pa->depth > pb->depth) pa = pa->parent;
			else pb = pb->parent;
		}

		while (pa != pb) {
			pa = pa->parent;
			pb = pb->parent;
		}

		cout << pa->index << endl;

		for (int i = 1; i <= n; ++i) {
			nodes[i]->Clear();
			nodes[i] = nullptr;
		}
	}
}