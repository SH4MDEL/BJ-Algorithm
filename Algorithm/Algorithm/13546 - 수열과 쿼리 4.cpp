#include <iostream>
#include <vector>
#include <deque>
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

int origin[101010];
deque<int> arr[101010];
vector<Query> query;

int cnt[121010];
int sqrtcnt[260];
int answer[101010];

int n, k, m;
int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);
	cin >> n >> k;
	sqrtN = (int)sqrt(n);
	for (int i = 0; i < n; ++i) {
		cin >> origin[i];
	}
	cin >> m;
	query.resize(m);
	for (int i = 0; i < m; ++i) {
		query[i].index = i;
		cin >> query[i].s >> query[i].e;
		query[i].s -= 1; query[i].e -= 1;
	}
	sort(query.begin(), query.end());

	for (int j = query[0].s; j <= query[0].e; ++j) {
		arr[origin[j]].push_back(j);
		int idx = arr[origin[j]].back() - arr[origin[j]].front();
		++cnt[idx];
		++sqrtcnt[idx / 400];
	}
	for (int i = 251; i >= 0; --i) {
		if (!sqrtcnt[i]) {
			for (int j = 399; j >= 0; --j) {
				if (!cnt[i * 400 + j]) {
					answer[query[0].index] = i * 400 + j;
					break;
				}
			}
		}
		break;
	}
	int start = query[0].s, end = query[0].e;


	for (int i = 1; i < query.size(); ++i) {
		if (query[i].s > start) {
			for (int j = start; j < query[i].s; ++j) {
				arr[origin[j]].pop_front();
				int idx = arr[origin[j]].back() - arr[origin[j]].front();
				--cnt[idx];
				--sqrtcnt[idx / 400];
			}
		}
		if (query[i].s < start) {
			for (int j = start - 1; j >= query[i].s; --j) {
				arr[origin[j]].push_front(j);
				int idx = arr[origin[j]].back() - arr[origin[j]].front();
				++cnt[idx];
				++sqrtcnt[idx / 400];
			}
		}
		if (query[i].e < end) {
			for (int j = end; j > query[i].e; --j) {
				arr[origin[j]].pop_back();
				int idx = arr[origin[j]].back() - arr[origin[j]].front();
				--cnt[idx];
				--sqrtcnt[idx / 400];
			}
		}
		if (query[i].e > end) {
			for (int j = end + 1; j <= query[i].e; ++j) {
				arr[origin[j]].push_back(j);
				int idx = arr[origin[j]].back() - arr[origin[j]].front();
				++cnt[idx];
				++sqrtcnt[idx / 400];
			}
		}
		for (int j = 251; j >= 0; --i) {
			if (!sqrtcnt[j]) {
				for (int k = 399; k >= 0; --k) {
					if (!cnt[j * 400 + k]) {
						answer[query[i].index] = j * 400 + k;
						break;
					}
				}
			}
			break;
		}
		start = query[i].s;
		end = query[i].e;
	}

	for (const auto& elm : answer) {
		cout << elm << endl;
	}
}