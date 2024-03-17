#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

struct Node;
Node* croot;

#define mod 1'000'000'007
#define prime 29
size_t hashfunc(const string& s) {
	size_t hash_value = 0;
	size_t p_pow = 1;
	for (const auto& c : s) {
		hash_value = (hash_value + (c - 'a' + 1) * p_pow) % mod;
		p_pow = (p_pow * prime) % mod;
	}
	return hash_value;
}

unordered_set<string, hash<string>> name;

struct Node {
	Node() { children.resize(26); }
	bool finished;

	vector<Node*> children;

	void insert(const string& s, int depth) {
		if (depth == s.length()) {
			finished = true;
			return;
		}
		if (!children[s[depth] - 'a']) children[s[depth] - 'a'] = new Node;
		children[s[depth] - 'a']->insert(s, depth + 1);
	}

	string search_color(const string& s, int depth) {
		if (depth == s.length()) return "No";
		if (finished) {
			if (name.count(s.substr(depth, s.length()))) return "Yes";
		}
		if (!children[s[depth] - 'a']) return "No";
		return children[s[depth] - 'a']->search_color(s, depth + 1);
	}
};

int c, n, q;

int main()
{
	fastip; sws;
	croot = new Node;
	cin >> c >> n;
	for (int i = 0; i < c; ++i) {
		string s;
		cin >> s;
		croot->insert(s, 0);
	}
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		name.insert(s);
	}
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string s;
		cin >> s;
		cout << croot->search_color(s, 0) << endl;
	}
}