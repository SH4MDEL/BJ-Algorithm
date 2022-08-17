#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#define inf 987654321 
#define endl "\n"
using namespace std;

unordered_map<string, string> disjoint_set;

int t, n;

string uf_find(string s)
{
	if (!(disjoint_set[s][0] >= 'A' && disjoint_set[s][0] <= 'z')) return s;
	return disjoint_set[s] = uf_find(disjoint_set[s]);
}

bool uf_union(string a, string b)
{
	a = uf_find(a);
	b = uf_find(b);
	if (a == b) {
		cout << -stoi(disjoint_set[a]) << endl;
		return false;
	}
	disjoint_set[a] = to_string(stoi(disjoint_set[a]) + stoi(disjoint_set[b]));
	disjoint_set[b] = a;
	cout << -stoi(disjoint_set[a]) << endl;
	return true;
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	string a, b;
	
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n;
		for (int j = 0; j < n; ++j) {
			cin >> a >> b;
			if (disjoint_set.find(a) == disjoint_set.end()) {
				disjoint_set[a] = "-1";
			}
			if (disjoint_set.find(b) == disjoint_set.end()) {
				disjoint_set[b] = "-1";
			}
			uf_union(a, b);
		}
		disjoint_set.clear();
	}
}
