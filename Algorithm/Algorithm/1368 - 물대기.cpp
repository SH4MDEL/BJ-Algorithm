#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

struct Node {
	int s, e, v;
	bool operator<(const Node& rhs) const {
		return v > rhs.v;
	}
};
priority_queue<Node> pq;
int n;
int disjoint_set[310];

int uf_find(int n) {
	if (disjoint_set[n] == -1) return n;
	return uf_find(disjoint_set[n]);
}

bool uf_union(int a, int b) {
	a = uf_find(a);
	b = uf_find(b);
	if (a == b) return false;
	disjoint_set[b] = a;
	return true;
}

int main() {
	fastip; sws;
	cin >> n;
	fill(disjoint_set, disjoint_set + n + 1, -1);
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		pq.push({ 0, i, a });
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int a;
			cin >> a;
			if (i != j) pq.push({ i, j, a });
		}
	}
	int count = 0, cost = 0;
	while (count != n) {
		int s = pq.top().s;
		int e = pq.top().e;
		int v = pq.top().v;
		pq.pop();
		if (uf_union(s, e)) {
			++count;
			cost += v;
		}
	}
	cout << cost;
}