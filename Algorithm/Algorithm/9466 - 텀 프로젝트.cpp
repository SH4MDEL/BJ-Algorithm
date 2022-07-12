#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

struct Status {
	int select;
	bool visited;
	bool finished;
	bool cycle;
	Status() {
		select = 0;
		visited = false;
		finished = false;
		cycle = false;
	}
};
Status status[100010];


int t, n, cnt;

void dfs(int next)
{
	if (status[next].finished) {
		status[next].visited = false;
		return;
	}
	if (status[next].visited) {

		int count = status[next].select;
		while (count != next) {
			status[count].visited = false;
			if (!status[count].finished) {
				status[count].finished = true;
				++cnt;
			}
			count = status[count].select;
		}
		status[next].visited = false;
		if (!status[next].finished) {
			status[next].finished = true;
			++cnt;
		}
		return;
	}

	status[next].visited = true;

	if (!status[next].cycle) {
		dfs(status[next].select);
		status[next].cycle = true;
	}

	status[next].visited = false;
	return;

}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> t;
	for (int i = 0; i < t; ++i) {

		cin >> n;

		cnt = 0;
		Status inputdata;
		fill(status, status + n, inputdata);

		for (int j = 0; j < n; ++j) {
			cin >> status[j].select;
			--status[j].select;
		}
		for (int j = 0; j < n; ++j) {
			if (!status[j].finished) {
				status[j].visited = true;
				dfs(status[j].select);
				status[j].visited = false;
			}
		}
		cout << n - cnt << endl;
	}

}