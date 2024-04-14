#include <iostream>
#include <ranges>
#include <algorithm>
#include <string>
#include <array>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define mod 1000LL
#define endl "\n"
using namespace std;

ll n, b;
array<array<ll, 5>, 5> matrix;

array<array<ll, 5>, 5> mul(const array<array<ll, 5>, 5>& mat1, const array<array<ll, 5>, 5>& mat2)
{
	array<array<ll, 5>, 5> ans = { 0 };
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				ans[i][j] += (mat1[i][k] * mat2[k][j]) % mod;
			}
			ans[i][j] %= mod;
		}
	}
	return ans;
}

array<array<ll, 5>, 5> square(const array<array<ll, 5>, 5>& mat, ll r)
{
	if (r == 1) {
		auto result = mat;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				result[i][j] %= mod;
			}
		}
		return result;
	}
	auto result = square(mat, r / 2);
	if (r % 2 == 0) {
		return mul(result, result);
	}
	return mul(mul(result, result), mat);
}

int main()
{
	fastip; sws;

	cin >> n >> b;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}
	auto ans = square(matrix, b);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}