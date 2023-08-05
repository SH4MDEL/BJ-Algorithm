// GOLD III 17299 - 오등큰수

#include <iostream>
#include <vector>
#include <stack>
#include <list>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

vector<int> v;
vector<int> answer;
vector<int> counting;
stack<int> s;
int n;

int main()
{
	fastip; sws;

	cin >> n;
	v.resize(n, 0);
	counting.resize(1000001, 0);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		++counting[v[i] - 1];
	}

	for (auto itr = v.rbegin(); itr != v.rend(); ++itr) {
		int ans = -1;
		while (!s.empty()) {
			if (counting[s.top() - 1] > counting[*itr - 1]) {
				ans = s.top();
				break;
			}
			else {
				s.pop();
			}
		}
		s.push(*itr);
		answer.push_back(ans);
	}
	for (auto itr = answer.rbegin(); itr != answer.rend(); ++itr) {
		cout << *itr << " ";
	}
}