#include <iostream>
#include <string>
#define endl "\n"
using namespace std;

int t, n;
string number;
bool judge;

struct table {
	bool finish;
	table* next[10];

	table() { 
		finish = false;
		for (int i = 0; i < 10; ++i) {
			next[i] = nullptr;
		}
	};

	void MakeNumberSet(string num, int depth) {
		int intnum = num[depth] - '0';
		if (finish) {
			judge = false;
			return;
		}
		if (num.size() == depth) {
			for (int i = 0; i < 10; ++i) {
				if (next[i]) {
					judge = false;
					return;
				}
			}
			finish = true;
			return;
		}
		if (next[intnum] == nullptr) {
			next[intnum] = new table;
		}
		next[intnum]->MakeNumberSet(num, depth + 1);
	}

	void reset() {
		for (int i = 0; i < 10; ++i) {
			if (next[i]) {
				next[i]->reset();
				delete next[i];
				next[i] = nullptr;
			}
		}
	}
};

table maintable;


int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> t;
	for (int i = 0; i < t; ++i) {
		judge = true;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			cin >> number;
			maintable.MakeNumberSet(number, 0);
		}
		if (judge) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		maintable.reset();
		maintable.finish = false;
	}
}