#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define mod 1'000'000'007
#define ll long long
#define endl "\n"
using namespace std;

ll n;
struct Matrix {
	ll m11, m12;
	ll m21, m22;

	Matrix operator*(const Matrix& rhs) const {
		Matrix m;
		m.m11 = ((m11 * rhs.m11) % mod + (m12 * rhs.m21) % mod) % mod;
		m.m12 = ((m11 * rhs.m12) % mod + (m12 * rhs.m22) % mod) % mod;
		m.m21 = ((m21 * rhs.m11) % mod + (m22 * rhs.m21) % mod) % mod;
		m.m22 = ((m21 * rhs.m12) % mod + (m22 * rhs.m22) % mod) % mod;
		return m;
	}
};
unordered_map<ll, Matrix> um;

Matrix search(ll num)
{
	if (um.count(num)) return um[num];

	if (num % 2LL == 0) {	
		return um[num] = search(num / 2LL) * search(num / 2LL);
	}
	return um[num] = search(num / 2LL) * search(num / 2LL) * um[1];
}

int main()
{
	fastip; sws;

	Matrix basis;
	basis.m11 = basis.m12 = basis.m21 = 1;
	basis.m22 = 0;
	um[1] = basis;

	cin >> n;
	if (n == 1) n += 1;
	cout << search(n - 1).m11 << endl;
}