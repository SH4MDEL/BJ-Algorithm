#include <iostream>
#include <string>
#include <unordered_set>
#include <map>
#include <memory>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

unordered_set<string> name;
string s;
struct Node {
	bool finished;

	map<char, shared_ptr<Node>> children;

	void insert(int depth) {
		if (depth == s.length()) {
			finished = true;
			return;
		}
		if (!children.count(s[depth])) children[s[depth]] = make_shared<Node>();
		children[s[depth]]->insert(depth + 1);
	}

	string search_color(int depth) {
		if (depth == s.length()) return "No";
		if (finished && name.count(s.substr(depth, s.length()))) return "Yes";
		if (!children.count(s[depth])) return "No";
		return children[s[depth]]->search_color(depth + 1);
	}
};
Node root;
int c, n, q;

int main()
{
	fastip; sws;
	root;
	cin >> c >> n;
	for (int i = 0; i < c; ++i) {
		cin >> s;
		root.insert(0);
	}
	for (int i = 0; i < n; ++i) {
		cin >> s;
		name.insert(s);
	}
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> s;
		cout << root.search_color(0) << endl;
	}
}