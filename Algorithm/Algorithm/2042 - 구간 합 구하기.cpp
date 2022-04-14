#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>


std::vector<long long> data;
std::vector<long long> tree;
int N, M, K, num, left, right;

long long mktree(int node, int l, int r)
{
	if (l == r) { return tree[node] = data[l]; }

	int mid = (l + r) / 2;
	
	return tree[node] = mktree(node * 2, l, mid) + mktree(node * 2 + 1, mid + 1, r);
}

long long sum(int l, int r, int node, int lnode, int rnode)
{
	if (lnode == l && rnode == r) {
		return tree[node];
	}
	int mid = (lnode + rnode) / 2;
	if (mid >= l && mid + 1 <= r) {
		return sum(l, mid, node * 2, lnode, l) + sum(mid + 1, r, node * 2 + 1, r, rnode);
	}
	if (mid >= r) {
		return sum(l, r, node * 2, lnode, mid);
	}
	if (mid + 1 <= l) {
		return sum(l, r, node * 2 + 1, mid, rnode);
	}
	printf("unexcept run!\n");
}

//int update(int data, int val)
//{
//
//}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	tree.resize(4 * N);
	data.resize(N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &num);
		data[i] = num;
	}
	mktree(1, 0, N - 1);
	for (const auto& elem : data) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;
	for (const auto& elem : tree) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < M + K; ++i) {
		scanf("%d %d", &left, &right);
		printf("%lld\n", sum(left, right, 1, 0, N - 1));
	}
}
