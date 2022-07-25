#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define endl "\n"
#define inf 987654321
using namespace std;

int sqrtN;

struct Query {
	int index, i, j;

	bool operator<(const Query& rhs) const {
		if (i / sqrtN != rhs.i / sqrtN) return (i / sqrtN < rhs.i / sqrtN);
		return (j < rhs.j);
	}
};

vector<Query> query;
vector<int> arr;
int counter1[100010];	// 해당 수가 몇개 들어있는지
int counter2[100010];
int maxcount;
vector<int> answer;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	maxcount = 0;
	int n, m;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sqrtN = (int)sqrt(n);
	cin >> m;
	query.resize(m);
	answer.resize(m);

	for (int i = 0; i < m; ++i) {
		query[i].index = i;
		cin >> query[i].i >> query[i].j;
	}
	sort(query.begin(), query.end());

	for (int i = query[0].i; i <= query[0].j; ++i) {
		if (counter1[arr[i - 1]] != 0) {
			--counter2[counter1[arr[i - 1]]];
		}
		++counter1[arr[i - 1]];
		++counter2[counter1[arr[i - 1]]];
		if (counter1[arr[i - 1]] > maxcount) {
			maxcount = counter1[arr[i - 1]];
		}
	}
	answer[query[0].index] = maxcount;

	for (int i = 1; i < query.size(); ++i) {
		if (query[i].i > query[i - 1].i) {
			for (int j = query[i - 1].i; j < query[i].i; ++j) {
				--counter2[counter1[arr[j - 1]]];
				if (counter1[arr[j - 1]] == maxcount && !counter2[counter1[arr[j - 1]]]) {
					--maxcount;
				}
				--counter1[arr[j - 1]];
				++counter2[counter1[arr[j - 1]]];
			}
		}
		if (query[i].i < query[i - 1].i) {
			for (int j = query[i].i; j < query[i - 1].i; ++j) {
				if (counter1[arr[j - 1]] != 0) {
					--counter2[counter1[arr[j - 1]]];
				}
				++counter1[arr[j - 1]];
				++counter2[counter1[arr[j - 1]]];
				if (counter1[arr[j - 1]] > maxcount) {
					maxcount = counter1[arr[j - 1]];
				}
			}
		}
		if (query[i].j > query[i - 1].j) {
			for (int j = query[i - 1].j + 1; j <= query[i].j; ++j) {
				if (counter1[arr[j - 1]] != 0) {
					--counter2[counter1[arr[j - 1]]];
				}
				++counter1[arr[j - 1]];
				++counter2[counter1[arr[j - 1]]];
				if (counter1[arr[j - 1]] > maxcount) {
					maxcount = counter1[arr[j - 1]];
				}
			}
		}
		if (query[i].j < query[i - 1].j) {
			for (int j = query[i].j + 1; j <= query[i - 1].j; ++j) {
				--counter2[counter1[arr[j - 1]]];
				if (counter1[arr[j - 1]] == maxcount && !counter2[counter1[arr[j - 1]]]) {
					--maxcount;
				}
				--counter1[arr[j - 1]];
				++counter2[counter1[arr[j - 1]]];
			}
		}
		answer[query[i].index] = maxcount;
	}
	for (const auto& elm : answer) {
		cout << elm << endl;
	}
}