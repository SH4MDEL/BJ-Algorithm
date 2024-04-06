#include <iostream>
#include <stack>
#include <vector>
#include <ranges>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int n, now = 1;
stack<int> s1, s2;
vector<int> v;

int main()
{
	fastip; sws;

	cin >> n;
	v.resize(n);
	for (auto& e : v | views::reverse) { 
		cin >> e; 
	}
	for (const auto& e : v) s1.push(e);
	while (!s1.empty() || !s2.empty()) {
		if (!s1.empty() && s1.top() == now) {
			s1.pop();
			++now;
		}
		else if (!s2.empty() && s2.top() == now) {
			s2.pop();
			++now;
		}
		else if (!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		else {
			break;
		}
	}
	if (s1.empty() && s2.empty()) cout << "Nice";
	else cout << "Sad";
}