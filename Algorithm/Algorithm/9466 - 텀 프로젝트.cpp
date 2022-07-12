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
	Status() {
		select = 0;
		visited = false;
		finished = false;
	}
};

void dfs(vector<Status>& status, int next)
{
	if (status[next].finished) {
		status[next].visited = false;
		return;
	}
	if (status[next].visited) {

		int count = status[next].select;
		while (count != next) {
			status[count].visited = false;
			status[count].finished = true;
			count = status[count].select;
		}
		status[next].visited = false;
		status[next].finished = true;
		return;
	}

	status[next].visited = true;

	dfs(status, status[next].select);

	status[next].visited = false;
	return;

}

int t, n;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> t;
	for (int i = 0; i < t; ++i) {
		vector<Status> status;
		cin >> n;
		status.resize(n);
		for (int j = 0; j < n; ++j) {
			cin >> status[j].select;
			status[j].select -= 1;
		}
		for (int j = 0; j < n; ++j) {
			if (!status[j].finished) {
				status[j].visited = true;
				dfs(status, status[j].select);
				status[j].visited = false;
			}
		}

		int count = 0;
		for (int j = 0; j < n; ++j) {
			if (!status[j].finished) {
				++count;
			}
		}
		cout << count << endl;
	}

}