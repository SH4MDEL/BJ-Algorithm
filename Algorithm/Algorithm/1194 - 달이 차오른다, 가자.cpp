#include <iostream>
#include <map>
#include <queue>
#define endl "\n"
#define inf 987654321
using namespace std;

char cmap[52][52];
int n, m;

map<pair<int, int>, int> visited_map;
queue<pair<int, int>> q;

int depthcount = inf;

void Search(int x, int y, int key, int depth)
{
	if (cmap[y][x] >= 'a' && cmap[y][x] <= 'f') {
		key |= (1 << (int)(cmap[y][x] - 'a'));

	}

	if ((visited_map.find(make_pair(y * (n + 1) + x, key))) != visited_map.end()) {
		if (visited_map[make_pair(y * (n + 1) + x, key)] < depth) {
			return;
		}
	}
	visited_map[make_pair(y * (n + 1) + x, key)] = depth;

	if (depth > depthcount) {
		return;
	}
	if (cmap[y][x] >= 'A' && cmap[y][x] <= 'F') {
		if (key & (1 << (int)(cmap[y][x] - 'A'))) {
		}
		else {
			return;
		}
	}
	if (cmap[y][x] == '#') {
		return;
	}

	if (cmap[y][x] == '1') {
		if (depthcount > depth) {
			depthcount = depth;
		}
		return;
	}


	Search(x - 1, y, key, depth + 1);
	Search(x + 1, y, key, depth + 1);
	Search(x, y - 1, key, depth + 1);
	Search(x, y + 1, key, depth + 1);
}

void bfs(int x, int y, int key) 
{
	q.push(make_pair(y * (n + 1) + x, key));
	visited_map[make_pair(y * (n + 1) + x, key)] = 1;

	[&]() {
		while (!q.empty()) {
			int qsize = q.size();

			for (int i = 0; i < qsize; ++i) {
				pair<int, int> current = q.front();
				cout << (current.first) / (n + 1) << ", " << (current.first) % (n + 2) << endl;
				cout << (current.first + (n + 1)) / (n + 1) << ", " << (current.first + (n + 1)) % (n + 1) << endl;
				cout << (current.first - (n + 1)) / (n + 1) << ", " << (current.first - (n + 1)) % (n + 1) << endl;
				cout << (current.first + 1) / (n + 1) << ", " << (current.first + 1) % (n + 1) << endl;
				cout << (current.first - 1) / (n + 1) << ", " << (current.first - 1) % (n + 1) << endl << endl;
				q.pop();

				//if ((visited_map.find(make_pair(current.first + (n + 1), current.second))) != visited_map.end()) {
				if (cmap[(current.first + (n + 1)) / (n + 1)][(current.first + (n + 1)) % (n + 1)] >= 'a' &&
					cmap[(current.first + (n + 1)) / (n + 1)][(current.first + (n + 1)) % (n + 1)] <= 'z') {
					int newkey = current.second | (1 << (int)(cmap[(current.first + (n + 1)) / (n + 1)][(current.first + (n + 1)) % (n + 1)] - 'a'));

					if (visited_map.find(make_pair(current.first + (n + 1), newkey)) == visited_map.end()) {
						q.push(make_pair(current.first + (n + 1), newkey));
						visited_map[make_pair(current.first + (n + 1), newkey)] += 1;
					}
				}
				if (cmap[(current.first + (n + 1)) / (n + 1)][(current.first + (n + 1)) % (n + 1)] >= 'A' &&
					cmap[(current.first + (n + 1)) / (n + 1)][(current.first + (n + 1)) % (n + 1)] <= 'Z') {
					if (current.second & (1 << (int)(cmap[(current.first + (n + 1)) / (n + 1)][(current.first + (n + 1)) % (n + 1)] - 'A'))) {

						if (visited_map.find(make_pair(current.first + (n + 1), current.second)) == visited_map.end()) {
							q.push(make_pair(current.first + (n + 1), current.second));
							visited_map[make_pair(current.first + (n + 1), current.second)] = visited_map[make_pair(current.first, current.second)] + 1;
						}
					}
				}
				if (cmap[(current.first + (n + 1)) / (n + 1)][(current.first + (n + 1)) % (n + 1)] == '.') {

					if (visited_map.find(make_pair(current.first + (n + 1), current.second)) == visited_map.end()) {
						q.push(make_pair(current.first + (n + 1), current.second));
						visited_map[make_pair(current.first + (n + 1), current.second)] += 1;
					}
				}
				if ((current.first + (n + 1)) / (n + 1) == n && (current.first + (n + 1)) % (n + 1) == m) {
					depthcount = visited_map[make_pair(current.first, current.second)] + 1;
					return;
				}


				if (cmap[(current.first - (n + 1)) / (n + 1)][(current.first - (n + 1)) % (n + 1)] >= 'a' &&
					cmap[(current.first - (n + 1)) / (n + 1)][(current.first - (n + 1)) % (n + 1)] <= 'z') {
					int newkey = current.second | (1 << (int)(cmap[(current.first - (n + 1)) / (n + 1)][(current.first - (n + 1)) % (n + 1)] - 'a'));

					if (visited_map.find(make_pair(current.first - (n + 1), newkey)) == visited_map.end()) {
						q.push(make_pair(current.first - (n + 1), newkey));
						visited_map[make_pair(current.first - (n + 1), newkey)] += 1;
					}
				}
				if (cmap[(current.first - (n + 1)) / (n + 1)][(current.first - (n + 1)) % (n + 1)] >= 'A' &&
					cmap[(current.first - (n + 1)) / (n + 1)][(current.first - (n + 1)) % (n + 1)] <= 'Z') {
					if (current.second & (1 << (int)(cmap[(current.first - (n + 1)) / (n + 1)][(current.first - (n + 1)) % (n + 1)] - 'A'))) {

						if (visited_map.find(make_pair(current.first - (n + 1), current.second)) == visited_map.end()) {
							q.push(make_pair(current.first - (n + 1), current.second));
							visited_map[make_pair(current.first - (n + 1), current.second)] = visited_map[make_pair(current.first, current.second)] + 1;
						}
					}
				}
				if (cmap[(current.first - (n + 1)) / (n + 1)][(current.first - (n + 1)) % (n + 1)] == '.') {

					if (visited_map.find(make_pair(current.first - (n + 1), current.second)) == visited_map.end()) {
						q.push(make_pair(current.first + (n + 1), current.second));
						visited_map[make_pair(current.first + (n + 1), current.second)] += 1;
					}
				}
				if ((current.first - (n + 1)) / (n + 1) == n && (current.first - (n + 1)) % (n + 1) == m) {
					depthcount = visited_map[make_pair(current.first, current.second)] + 1;
					return;
				}


				if (cmap[(current.first + 1) / (n + 1)][(current.first + 1) % (n + 1)] >= 'a' &&
					cmap[(current.first + 1) / (n + 1)][(current.first + 1) % (n + 1)] <= 'z') {
					int newkey = current.second | (1 << (int)(cmap[(current.first + 1) / (n + 1)][(current.first + 1) % (n + 1)] - 'a'));

					if (visited_map.find(make_pair(current.first + 1, newkey)) == visited_map.end()) {
						q.push(make_pair(current.first + 1, newkey));
						visited_map[make_pair(current.first + 1, newkey)] += 1;
					}
				}
				if (cmap[(current.first + 1) / (n + 1)][(current.first + 1) % (n + 1)] >= 'A' &&
					cmap[(current.first + 1) / (n + 1)][(current.first + 1) % (n + 1)] <= 'Z') {
					if (current.second & (1 << (int)(cmap[(current.first + 1) / (n + 1)][(current.first + 1) % (n + 1)] - 'A'))) {

						if (visited_map.find(make_pair(current.first + 1, current.second)) == visited_map.end()) {
							q.push(make_pair(current.first + 1, current.second));
							visited_map[make_pair(current.first + 1, current.second)] = visited_map[make_pair(current.first, current.second)] + 1;
						}
					}
				}
				if (cmap[(current.first + 1) / (n + 1)][(current.first + 1) % (n + 1)] == '.') {

					if (visited_map.find(make_pair(current.first + 1, current.second)) == visited_map.end()) {
						q.push(make_pair(current.first + 1, current.second));
						visited_map[make_pair(current.first + 1, current.second)] += 1;
					}
				}
				if ((current.first + 1) / (n + 1) == n && (current.first + 1) % (n + 1) == m) {
					depthcount = visited_map[make_pair(current.first, current.second)] + 1;
					return;
				}


				if (cmap[(current.first - 1) / (n + 1)][(current.first - 1) % (n + 1)] >= 'a' &&
					cmap[(current.first - 1) / (n + 1)][(current.first - 1) % (n + 1)] <= 'z') {
					int newkey = current.second | (1 << (int)(cmap[(current.first - 1) / (n + 1)][(current.first - 1) % (n + 1)] - 'a'));

					if (visited_map.find(make_pair(current.first - 1, newkey)) == visited_map.end()) {
						q.push(make_pair(current.first - 1, newkey));
						visited_map[make_pair(current.first - 1, newkey)] += 1;
					}
				}
				if (cmap[(current.first - 1) / (n + 1)][(current.first - 1) % (n + 1)] >= 'A' &&
					cmap[(current.first - 1) / (n + 1)][(current.first - 1) % (n + 1)] <= 'Z') {
					if (current.second & (1 << (int)(cmap[(current.first - 1) / (n + 1)][(current.first - 1) % (n + 1)] - 'A'))) {

						if (visited_map.find(make_pair(current.first - 1, current.second)) == visited_map.end()) {
							q.push(make_pair(current.first - 1, current.second));
							visited_map[make_pair(current.first - 1, current.second)] = visited_map[make_pair(current.first, current.second)] + 1;
						}
					}
				}
				if (cmap[(current.first - 1) / (n + 1)][(current.first - 1) % (n + 1)] == '.') {

					if (visited_map.find(make_pair(current.first - 1, current.second)) == visited_map.end()) {
						q.push(make_pair(current.first - 1, current.second));
						visited_map[make_pair(current.first - 1, current.second)] += 1;
					}
				}
				if ((current.first - 1) / (n + 1) == n && (current.first - 1) % (n + 1) == m) {
					depthcount = visited_map[make_pair(current.first, current.second)] + 1;
					return;
				}

				//}
			}
		}
	}();
}

void bfsall(int startx, int starty)
{

}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	int startx = 0, starty = 0;

	for (int i = 0; i < 52; ++i) {
		for (int j = 0; j < 52; ++j) {
			cmap[i][j] = '#';
		}
	}
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> cmap[i][j];
			if (cmap[i][j] == '0') {
				starty = i, startx = j;
			}
		}
	}
	cout << "start : " << starty << ", " << startx << endl;
	bfs(startx, starty, 0);
	if (depthcount == inf) {
		cout << "-1" << endl;
	}
	else {
		cout << depthcount << endl;
	}
}