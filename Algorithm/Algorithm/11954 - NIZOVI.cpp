#include <iostream>
#include <string>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define mod 1'000'000'000
#define ll long long
#define endl "\n"
using namespace std;

string s;

void preprocess(bool first, int now) 
{
	if (first) {
		cout << "\n";
		for (int i = 0; i < now; ++i) {
			cout << "  ";
		}
	}
}

int main()
{
	fastip; sws;

	cin >> s;
	int now = 0;
	bool first = false;
	char prv = 0;
	for (const auto& c : s) {
		switch (c)
		{
		case '{':
			preprocess(first, now);
			cout << "{";
			first = true;
			++now;
			break;
		case '}':
			--now;
			preprocess(first, now);
			cout << "}";
			first = true;
			break;
		case ',':
			cout << ",";
			first = true;
			break;
		default:
			if (prv == '{' || prv == ',') preprocess(first, now);
			first = true;
			cout << c;
			break;
		}
		prv = c;
	}

}