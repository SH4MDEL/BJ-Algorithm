#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define endl "\n"
#define inf 987654321
using namespace std;

int sqrtN;

struct Query {
	int index, s, e;

	bool operator<(const Query& rhs) const {
		if (s / sqrtN != rhs.s / sqrtN) return (s / sqrtN < rhs.s / sqrtN);
		return (e < rhs.e);
	}
};

long long num[1000010];

int main()
{
	int n, t;
	cin >> n >> t;
	vector<int> arr(n);
	vector<Query> vq(t);
	vector<long long> answer(t);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < t; ++i) {
		vq[i].index = i;
		cin >> vq[i].s >> vq[i].e;
		vq[i].s -= 1; vq[i].e -= 1;
	}
	sort(vq.begin(), vq.end());

	long long sum = 0;
	for (int i = vq[0].s; i <= vq[0].e; ++i) {

	}
}