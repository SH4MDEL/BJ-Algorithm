#include <iostream>
#include <vector>
#define endl "\n"
#define inf 987654321
using namespace std;

int init(vector<int>& arr, vector<int>& tree, int node, int start, int end)
{
	if (start == end) return tree[node] = start;

	int mid = (start + end) / 2;

	int a = init(arr, tree, node * 2, start, mid);
	int b = init(arr, tree, node * 2, mid + 1, end);
	if (arr[a] > arr[b]) return b;
	return a;
}

void update(vector<int>& arr, vector<int>& tree, int node, int start, int end, int index)
{
	if (index < start || index > end) return;

	if (arr[tree[node]] > arr[index]) {

	}

	if (start != end) {
		int mid = (start + end) / 2;
		update(arr, tree, node * 2, start, mid, index);
		update(arr, tree, node * 2 + 1, mid + 1, end, index);
	}
}

void find(vector<int>& tree, int node, int start, int end, int left, int right)
{

}