#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
#define inf 987654321
using namespace std;

int n;

struct Answer_Data {
	long long num;
	int start, end;

	bool operator<(const Answer_Data& rhs) const { return num < rhs.num; }
	Answer_Data& operator=(const Answer_Data& rhs) {
		num = rhs.num;
		start = rhs.start;
		end = rhs.end;
		return *this;
	}
};

Answer_Data init_sum(vector<long long>& arr, vector<Answer_Data>& tree, int node, int start, int end)
{
	tree[node].start = start;
	tree[node].end = end;

	if (start == end) {
		tree[node].num = arr[start];
		return tree[node];
	}
	int mid = (start + end) / 2;
	tree[node].num = init_sum(arr, tree, node * 2, start, mid).num + init_sum(arr, tree, node * 2 + 1, mid + 1, end).num;
	return tree[node];
}

int init_min(vector<long long>& arr, vector<int>& tree, int node, int start, int end)
{
	if (start == end) return tree[node] = start;

	int mid = (start + end) / 2;

	int a = init_min(arr, tree, node * 2, start, mid);
	int b = init_min(arr, tree, node * 2 + 1, mid + 1, end);
	if (arr[a] > arr[b]) return tree[node] = b;
	if (arr[a] < arr[b]) return tree[node] = a;
	return tree[node] = min(a, b);
}

Answer_Data find_sum(vector<Answer_Data>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) {
		Answer_Data ad;
		ad.num = -1;
		return ad;
	}

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	Answer_Data ad;
	Answer_Data a = find_sum(tree, node * 2, start, mid, left, right);
	Answer_Data b = find_sum(tree, node * 2 + 1, mid + 1, end, left, right);
	if (a.num != -1 && b.num != -1) {
		ad.num = a.num + b.num;
		ad.start = a.start;
		ad.end = b.end;
	}
	else if (a.num != -1) {
		ad.num = a.num;
		ad.start = a.start;
		ad.end = a.end;
	}
	else if (b.num != -1) {
		ad.num = b.num;
		ad.start = b.start;
		ad.end = b.end;
	}
	else {
		ad.num = -1;
	}
	return ad;
}

int find_min(vector<long long>& arr, vector<int>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return n;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	int a = find_min(arr, tree, node * 2, start, mid, left, right);
	int b = find_min(arr, tree, node * 2 + 1, mid + 1, end, left, right);
	if (arr[a] > arr[b]) return b;
	if (arr[a] < arr[b]) return a;
	return min(a, b);
}

Answer_Data find_answer(vector<long long>& arr, vector<Answer_Data>& sumtree, vector<int>& mintree, int node, int start, int end)
{
	if (start == end) {
		Answer_Data ad;
		ad.start = start;
		ad.end = end;
		ad.num = arr[start] * arr[start];
		return ad;
	}

	int arrnum = find_min(arr, mintree, node, 0, n - 1, start, end);
	Answer_Data ad = find_sum(sumtree, node, 0, n - 1, start, end);
	ad.num *= arr[arrnum];
	if (arrnum > start) {
		ad = max(ad, find_answer(arr, sumtree, mintree, node, start, arrnum - 1));
	}
	if (arrnum < end) {
		ad = max(ad, find_answer(arr, sumtree, mintree, node, arrnum + 1, end));
	}
	return ad;

}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	cin >> n;
	vector<long long> arr(n + 1);
	vector<Answer_Data> sumtree(n * 4);
	vector<int> mintree(n * 4);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	arr[n] = inf;
	init_sum(arr, sumtree, 1, 0, n - 1);
	init_min(arr, mintree, 1, 0, n - 1);

	Answer_Data ad = find_answer(arr, sumtree, mintree, 1, 0, n - 1);
	cout << ad.num << endl;
	cout << ad.start + 1 << " " << ad.end + 1 << endl;
}