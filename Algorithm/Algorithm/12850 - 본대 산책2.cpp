#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <bitset>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
#define mod 1'000'000'007
#define ll long long
using namespace std;

// n i j
ll cache[35][8][8]; // 2^n번 이동했을 때 어디서 시작해서 어디에 몇 번 방문?
ll junction[2][8];
ll d;

int main()
{
	fastip; sws;

	for (int i = 0; const ll e : { 0, 1, 1, 0, 0, 0, 0, 0 }) cache[0][0][i++] = e; // 정보
	for (int i = 0; const ll e : { 1, 0, 1, 1, 0, 0, 0, 0 }) cache[0][1][i++] = e; // 전산
	for (int i = 0; const ll e : { 1, 1, 0, 1, 1, 0, 0, 0 }) cache[0][2][i++] = e; // 미래
	for (int i = 0; const ll e : { 0, 1, 1, 0, 1, 1, 0, 0 }) cache[0][3][i++] = e; // 신앙
	for (int i = 0; const ll e : { 0, 0, 1, 1, 0, 1, 0, 1 }) cache[0][4][i++] = e; // 한경직
	for (int i = 0; const ll e : { 0, 0, 0, 1, 1, 0, 1, 0 }) cache[0][5][i++] = e; // 진리
	for (int i = 0; const ll e : { 0, 0, 0, 0, 0, 1, 0, 1 }) cache[0][6][i++] = e; // 학생회
	for (int i = 0; const ll e : { 0, 0, 0, 0, 1, 0, 1, 0 }) cache[0][7][i++] = e; // 형남

	for (int i = 1; i <= 30; ++i) {
		for (int from = 0; from < 8; ++from) {
			for (int to = 0; to < 8; ++to) {
				for (int via = 0; via < 8; ++via) {
					cache[i][from][to] += 
						((cache[i - 1][from][via] % mod) * (cache[i - 1][via][to]) % mod) % mod;
					cache[i][from][to] %= mod;
				}
			}
		}
	}
	cin >> d;
	int count = 0;
	while (1) {
		if (d % 2) {
			for (int i = 0; i < 8; ++i) {
				junction[0][i] = cache[count][0][i];
			}
			++count; 
			d /= 2;
			break;
		}
		++count; 
		d /= 2;
	}
	while (d) {
		if (d % 2) {
			for (int to = 0; to < 8; ++to) {
				for (int via = 0; via < 8; ++via) {
					junction[1][to] += 
						((junction[0][via] % mod) * (cache[count][via][to] % mod)) % mod;
				}
				junction[1][to] %= mod;
			}

			for (int i = 0; i < 8; ++i) {
				junction[0][i] = junction[1][i];
				junction[1][i] = 0LL;
			}
		}
		++count;
		d /= 2;
	}

	cout << junction[0][0] % mod;
}