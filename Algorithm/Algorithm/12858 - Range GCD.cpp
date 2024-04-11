#include <iostream>
#include <ranges>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

ll n, q;
vector<ll> arr, lazy, segtree, gcdtree;

ll gcd(ll a, ll b)
{
	if (a == 0) return b;
	if (b == 0) return a;
	return a % b == 0 ? b : gcd(b, a % b);
}

// GCD(a, b, c, d, e) == GCD(a - 0, b - a, c - b, d - c, e - d)
// GCD(a+x, b+x, c+x, d+x, e+x) == GCD(a+x, GCD(b-a, c-b, d-c, e-d));
// (a, b+x, c+x, d+x, e)
// GCD(b+x, c+x, d+x, e) == GCD(b+x, GCD(c-b, b-c))

void make_tree(ll node, ll start, ll end)
{
	if (start == end) {
		segtree[node] = arr[start];
		return;
	}

	ll mid = (start + end) / 2;
	make_tree(node * 2, start, mid);
	make_tree(node * 2 + 1, mid + 1, end);
}

void propagate(ll node, ll start, ll end)
{
	if (lazy[node]) {
		if (start == end) {
			segtree[node] += lazy[node];
		}
		else {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void range_update(ll node, ll start, ll end, ll left, ll right, ll diff)
{
	propagate(node, start, end);
	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		if (start == end) {
			segtree[node] += diff;
		}
		else {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	ll mid = (start + end) / 2;
	range_update(node * 2, start, mid, left, right, diff);
	range_update(node * 2 + 1, mid + 1, end, left, right, diff);
}

ll seg_find(ll node, ll start, ll end, ll index)
{
	propagate(node, start, end);
	if (start > index || index > end) return 0;
	if (start == end) return segtree[node];
	ll mid = (start + end) / 2;
	return seg_find(node * 2, start, mid, index) + 
		seg_find(node * 2 + 1, mid + 1, end, index);
}

ll make_gcd(ll node, ll start, ll end)
{
	if (start == end) {
		return gcdtree[node] = abs(arr[start] - arr[start - 1]);
	}

	ll mid = (start + end) / 2;
	return gcdtree[node] = 
		gcd(make_gcd(node * 2, start, mid), 
			make_gcd(node * 2 + 1, mid + 1, end));
}

void gcd_update(ll node, ll start, ll end, ll index, ll diff)
{
	if (start > index || index > end) return;
	if (start == end) {
		gcdtree[node] = diff;
		return;
	}
	ll mid = (start + end) / 2;
	gcd_update(node * 2, start, mid, index, diff);
	gcd_update(node * 2 + 1, mid + 1, end, index, diff);
	gcdtree[node] = gcd(gcdtree[node * 2], gcdtree[node * 2 + 1]);
}

ll gcd_find(ll node, ll start, ll end, ll left, ll right)
{
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) {
		return gcdtree[node];
	}
	ll mid = (start + end) / 2;
	return gcdtree[node] = gcd(
		gcd_find(node * 2, start, mid, left, right),
		gcd_find(node * 2 + 1, mid + 1, end, left, right));
}

int main()
{
	fastip; sws;

	cin >> n;
	arr.resize(n + 1);
	segtree.resize(n * 4);
	gcdtree.resize(n * 4);
	lazy.resize(n * 4);
	for (const auto& i : views::iota(1, n + 1)) cin >> arr[i];
	make_tree(1, 1, n);
	make_gcd(1, 1, n);
	cin >> q;
	while (q--) {
		ll t, a, b;
		cin >> t >> a >> b;
		if (!t) {
			cout << gcd(seg_find(1, 1, n, a), gcd_find(1, 1, n, a + 1, b)) << endl;
		}
		else {
			ll l = seg_find(1, 1, n, a - 1);
			ll r = seg_find(1, 1, n, b + 1);
			range_update(1, 1, n, a, b, t);
			gcd_update(1, 1, n, a, abs(seg_find(1, 1, n, a) - l));
			gcd_update(1, 1, n, b + 1, abs(seg_find(1, 1, n, b) - r));
		}
	}
}