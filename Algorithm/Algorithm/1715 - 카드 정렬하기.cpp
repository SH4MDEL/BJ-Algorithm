#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

int count, sum, data, all;

int main()
{
	scanf("%d", &count);
	for (int i = 0; i < count; ++i) {
		scanf("%d", &data);
		pq.push(data);
	}
	if (count == 1) {
		printf("0\n");
	}
	else {
		while (pq.size() != 1 && pq.size() != 2) {
			sum = pq.top();
			pq.pop();
			sum += pq.top();
			pq.pop();
			all += sum;
			pq.push(sum);
		}
		if (pq.size() == 1) {
			all += pq.top();
		}
		else {
			sum = pq.top();
			pq.pop();
			sum += pq.top();
			all += sum;
		}
		printf("%d\n", all);
	}
}