#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

std::priority_queue<int, std::vector<int>, std::greater<int>> minq;

int count, num;

int main()
{
	scanf("%d", &count);
	for (int i = 0; i < count; ++i) {
		scanf("%d", &num);
		if (num == 0) {
			if (minq.size() == 0) {
				printf("0\n");
			}
			else {
				printf("%d\n", minq.top());
				minq.pop();
			}
		}
		else {
			minq.push(num);
		}
	}
}