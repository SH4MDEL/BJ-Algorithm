#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, m;
char map[8][8];
int minimum = inf;
vector<pair<char, char>> coord;

void search(vector<char> v)
{
	if (v.size() == coord.size()) {
		char simulation[8][8];
		memcpy(simulation, map, sizeof(char) * 8 * 8);
		for (int i = 0; const auto & e : coord) {
			auto y = e.first;
			auto x = e.second;
			if (map[y][x] == 1) {
				// »ó
				if (v[i] == 1) {
					for (int i = y; i >= 0; --i) {
						if (simulation[i][x] == 6) break;
						simulation[i][x] = '#';
					}
				}
				// ÇÏ
				if (v[i] == 2) {
					for (int i = y; i < n; ++i) {
						if (simulation[i][x] == 6) break;
						simulation[i][x] = '#';
					}
				}
				// ÁÂ
				if (v[i] == 3) {
					for (int i = x; i >= 0; --i) {
						if (simulation[y][i] == 6) break;
						simulation[y][i] = '#';
					}
				}
				// ¿ì
				if (v[i] == 4) {
					for (int i = x; i < m; ++i) {
						if (simulation[y][i] == 6) break;
						simulation[y][i] = '#';
					}
				}
			}
			if (map[y][x] == 2) {
				// »óÇÏ
				if (v[i] == 1) {
					for (int i = y; i >= 0; --i) {
						if (simulation[i][x] == 6) break;
						simulation[i][x] = '#';
					}
					for (int i = y; i < n; ++i) {
						if (simulation[i][x] == 6) break;
						simulation[i][x] = '#';
					}
				}
				// ÁÂ¿ì
				if (v[i] == 2) {
					for (int i = x; i >= 0; --i) {
						if (simulation[y][i] == 6) break;
						simulation[y][i] = '#';
					}
					for (int i = x; i < m; ++i) {
						if (simulation[y][i] == 6) break;
						simulation[y][i] = '#';
					}
				}
			}
			if (map[y][x] == 3) {
				// ¿ì»ó
				if (v[i] == 1) {
					for (int i = x; i < m; ++i) {
						if (simulation[y][i] == 6) break;
						simulation[y][i] = '#';

					}
					for (int i = y; i >= 0; --i) {
						if (simulation[i][x] == 6) break;
						simulation[i][x] = '#';
					}
				}
				// ¿ìÇÏ
				if (v[i] == 2) {
					for (int i = x; i < m; ++i) {
						if (simulation[y][i] == 6) break;
						simulation[y][i] = '#';
					}
					for (int i = y; i < n; ++i) {
						if (simulation[i][x] == 6) break;
						simulation[i][x] = '#';
					}
				}
				// ÁÂ»ó
				if (v[i] == 3) {
					for (int i = x; i >= 0; --i) {
						if (simulation[y][i] == 6) break;
						simulation[y][i] = '#';
					}
					for (int i = y; i >= 0; --i) {
						if (simulation[i][x] == 6) break;
						simulation[i][x] = '#';
					}
				}
				// ÁÂÇÏ
				if (v[i] == 4) {
					for (int i = x; i >= 0; --i) {
						if (simulation[y][i] == 6) break;
						simulation[y][i] = '#';
					}
					for (int i = y; i < n; ++i) {
						if (simulation[i][x] == 6) break;
						simulation[i][x] = '#';
					}
				}
			}
			if (map[y][x] == 4) {
				// ÁÂ¿ì»ó
				if (v[i] == 1) {
					for (int i = x; i >= 0; --i) {
						if (simulation[y][i] == 6) break;
						simulation[y][i] = '#';
					}
					for (int i = x; i < m; ++i) {
						if (simulation[y][i] == 6) break;
						simulation[y][i] = '#';
					}
					for (int i = y; i >= 0; --i) {
						if (simulation[i][x] == 6) break;
						simulation[i][x] = '#';
					}
				}
				// ÁÂ¿ìÇÏ
				if (v[i] == 2) {
					for (int i = x; i >= 0; --i) {
						if (simulation[y][i] == 6) break;
						simulation[y][i] = '#';
					}
					for (int i = x; i < m; ++i) {
						if (simulation[y][i] == 6) break;
						simulation[y][i] = '#';
					}
					for (int i = y; i < n; ++i) {
						if (simulation[i][x] == 6) break;
						simulation[i][x] = '#';
					}
				}
				// »óÇÏÁÂ
				if (v[i] == 3) {
					for (int i = y; i >= 0; --i) {
						if (simulation[i][x] == 6) break;
						simulation[i][x] = '#';
					}
					for (int i = y; i < n; ++i) {
						if (simulation[i][x] == 6) break;
						simulation[i][x] = '#';
					}
					for (int i = x; i >= 0; --i) {
						if (simulation[y][i] == 6) break;
						simulation[y][i] = '#';
					}
				}
				// »óÇÏ¿ì
				if (v[i] == 4) {
					for (int i = y; i >= 0; --i) {
						if (simulation[i][x] == 6) break;
						simulation[i][x] = '#';
					}
					for (int i = y; i < n; ++i) {
						if (simulation[i][x] == 6) break;
						simulation[i][x] = '#';
					}
					for (int i = x; i < m; ++i) {
						if (simulation[y][i] == 6) break;
						simulation[y][i] = '#';
					}
				}
			}
			if (map[y][x] == 5) {
				for (int i = y; i >= 0; --i) {
					if (simulation[i][x] == 6) break;
					simulation[i][x] = '#';
				}
				for (int i = y; i < n; ++i) {
					if (simulation[i][x] == 6) break;
					simulation[i][x] = '#';
				}
				for (int i = x; i >= 0; --i) {
					if (simulation[y][i] == 6) break;
					simulation[y][i] = '#';
				}
				for (int i = x; i < m; ++i) {
					if (simulation[y][i] == 6) break;
					simulation[y][i] = '#';
				}
			}
			++i;
		}

		int count = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (simulation[i][j] != '#' && simulation[i][j] != 6) {
					++count;
				}
			}
		}

		minimum = min(minimum, count);
		return;
	}
	
	auto now = v.size();
	auto y = coord[now].first;
	auto x = coord[now].second;
	v.push_back(1);
	if (map[y][x] == 1) {
		search(v);
		v.back() = 2;
		search(v);
		v.back() = 3;
		search(v);
		v.back() = 4;
		search(v);
	}
	if (map[y][x] == 2) {
		search(v);
		v.back() = 2;
		search(v);
	}
	if (map[y][x] == 3) {
		search(v);
		v.back() = 2;
		search(v);
		v.back() = 3;
		search(v);
		v.back() = 4;
		search(v);
	}
	if (map[y][x] == 4) {
		search(v);
		v.back() = 2;
		search(v);
		v.back() = 3;
		search(v);
		v.back() = 4;
		search(v);
	}
	if (map[y][x] == 5) {
		search(v);
	}
}

int main()
{
	fastip; sws;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int input;
			cin >> input;
			map[i][j] = input;
			if (map[i][j] != 0 && map[i][j] != 6) {
				coord.emplace_back(i, j);
			}
		}
	}
	vector<char> v;
	search(v);
	cout << minimum;
}