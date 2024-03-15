#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

struct Node {
	unordered_map<char, shared_ptr<Node>> m;
	bool finished;

	void make_node(const string& s, int d) {
		if (s.size() == d) {
			finished = true;
			return;
		}
		if (!m.count(s[d])) m.insert({ s[d], make_shared<Node>() });
		m[s[d]]->make_node(s, d + 1);
	}

	int search(int count, int depth)
	{
		int ans = 0;
		if (!m.size()) return count;

		if (depth == 0 && m.size() == 1) {
			for (const auto& [name, node] : m) {
				ans += node->search(count + 1, depth + 1);
			}
			return ans;
		}

		if (finished) {
			if (m.size()) {
				ans += count;
			}
			else {
				return ans += count + 1;
			}
			for (const auto& [name, node] : m) {
				ans += node->search(count + 1, depth + 1);
			}
			return ans;
		}

		if (m.size() == 1) {
			for (const auto& [name, node] : m) {
				ans += node->search(count, depth + 1);
			}
			return ans;
		}
		
		for (const auto& [name, node] : m) {
			ans += node->search(count + 1, depth + 1);
		}
		return ans;
	}
};
int n;

int main()
{
	fastip; sws;
	cout << fixed; cout.precision(2);

	while (cin >> n) {
		auto node = make_shared<Node>();
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			node->make_node(s, 0);
		}

		cout << static_cast<double>(node->search(0, 0)) / 
			static_cast<double>(n) << endl;
	}
}