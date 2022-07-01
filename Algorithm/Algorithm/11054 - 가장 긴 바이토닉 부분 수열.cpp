#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
vector<int> numlist;
vector<int> startdistance;
deque<int> enddistance;
priority_queue<int> answer;


int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	int inputnum;
	numlist.push_back(0); startdistance.push_back(0); enddistance.push_front(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> inputnum;
		numlist.push_back(inputnum);
		startdistance.push_back(-1);
		enddistance.push_front(-1);
	}
	enddistance.push_back(0); numlist.push_back(0);

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (numlist[i] > numlist[j] && startdistance[j] >= startdistance[i]) {
				startdistance[i] = startdistance[j] + 1;
			}
		}
	}

	for (int i = n; i >= 1; --i) {
		for (int j = n + 1; j >= i; --j) {
			if (numlist[i] > numlist[j] && enddistance[j] >= enddistance[i]) {
				enddistance[i] = enddistance[j] + 1;
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		answer.push(startdistance[i] + enddistance[i] - 1);
	}
	cout << answer.top() << endl;
}