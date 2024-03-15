#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int n, k;

struct Node {
	Node(int d) : depth{ d } {}
	map<string, shared_ptr<Node>> m;
	int depth;

	shared_ptr<Node> push(const string& s) {
		if (m.find(s) == m.end()) {
			m.insert({ s, make_shared<Node>(depth + 1) });
		}
		return m[s];
	}

	void print() {
		child_print();
	}
private:
	void child_print() {
		for (auto& [name, node] : m) {
			for (int i = 0; i < node->depth; ++i) cout << "--";
			cout << name << endl;
			node->print();
		}
	}
};

int main()
{
	fastip; sws;

	auto root = make_shared<Node>(-1);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		auto now = root;
		for (int j = 0; j < k; ++j) {
			string s;
			cin >> s;
			now = now->push(s);
		}
	}

	root->print();
}