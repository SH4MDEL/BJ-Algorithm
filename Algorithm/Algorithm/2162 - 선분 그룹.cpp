#include <iostream>
#include <vector>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define ll long long
using namespace std;

int coord[3030][4];
int n, a;
vector<int> disjoint_set;

int ccw(int vx1, int vy1, int vx2, int vy2, int vx3, int vy3)
{
	ll result = (vx2 - vx1) * (vy3 - vy2) - (vx3 - vx2) * (vy2 - vy1);
	if (result > 0) return 1;
	else if (result < 0) return -1;
	else return 0;
}

bool check(int x1, int y1, int x2, int y2, int x3, int y3)
{
	if (x1 <= x3 && x3 <= x2 && y1 <= y3 && y3 <= y2) return true;
	if (x1 <= x3 && x3 <= x2 && y1 >= y3 && y3 >= y2) return true;
	if (x2 <= x3 && x3 <= x1 && y2 <= y3 && y3 <= y1) return true;
	if (x2 <= x3 && x3 <= x1 && y2 >= y3 && y3 >= y1) return true;
	return false;
}

bool segment(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	int result1 = ccw(x1, y1, x2, y2, x3, y3);
	int result2 = ccw(x1, y1, x2, y2, x4, y4);
	int result3 = ccw(x3, y3, x4, y4, x1, y1);
	int result4 = ccw(x3, y3, x4, y4, x2, y2);
	if (result1 == 0 || result2 == 0 || result3 == 0 || result4 == 0) {
		bool checker = false;
		if (result1 == 0) {
			if (check(x1, y1, x2, y2, x3, y3)) checker = true;
		}
		if (result2 == 0) {
			if (check(x1, y1, x2, y2, x4, y4)) checker = true;
		}
		if (result3 == 0) {
			if (check(x3, y3, x4, y4, x1, y1)) checker = true;
		}
		if (result4 == 0) {
			if (check(x3, y3, x4, y4, x2, y2)) checker = true;
		}
		if (checker) return true;
		return false;
	}
	else if (((result1 == 1 && result2 == -1) || (result1 == -1 && result2 == 1)) &&
		((result3 == 1 && result4 == -1) || (result3 == -1 && result4 == 1))) return true;
	else return false;
}

int uf_find(int a)
{
	if (disjoint_set[a] <= -1) return a;
	return disjoint_set[a] = uf_find(disjoint_set[a]);
}

bool uf_union(int a, int b)
{
	a = uf_find(a);
	b = uf_find(b);
	if (a == b) return false;
	disjoint_set[a] += disjoint_set[b];
	disjoint_set[b] = a;
	return true;
}

int main()
{
	fastip; sws;

	cin >> n;
	a = n;
	disjoint_set.resize(n + 1, -1);
	for (int i = 1; i <= n; ++i) {
		cin >> coord[i][0] >> coord[i][1] >> coord[i][2] >> coord[i][3];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i < j && segment(coord[i][0], coord[i][1], coord[i][2], coord[i][3],
				coord[j][0], coord[j][1], coord[j][2], coord[j][3])) {
				if (uf_union(i, j)) {

				}
			}
		}
	}
	
	cout << count_if(disjoint_set.begin() + 1, disjoint_set.end(), [](const int& e) {
		return e < 0;
		}) << endl
		<< -(*min_element(disjoint_set.begin() + 1, disjoint_set.end()));
}