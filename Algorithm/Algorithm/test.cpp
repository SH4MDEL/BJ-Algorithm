#include <iostream>
#include <math.h>
#include <map>
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, sum;

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	map<int, int> asdf;
	cout << asdf.size() << endl;;
	++asdf[1];
	++asdf[1];
	++asdf[1];
	cout << asdf.size() << endl;;
	++asdf[2];
	++asdf[3];
	++asdf[4];
	cout << asdf[1] << endl;;
	--asdf[1];
	--asdf[1];
	--asdf[1];
	cout << asdf.size() << endl;;
}