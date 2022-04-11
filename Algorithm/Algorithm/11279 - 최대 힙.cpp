#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

std::priority_queue<int> maxq;

int count, num;

int main()
{
	scanf("%d", &count);
	for (int i = 0; i < count; ++i) {
		scanf("%d", &num);
		if (num == 0) {
			if (maxq.size() == 0) {
				printf("0\n");
			}
			else {
				printf("%d\n", maxq.top());
				maxq.pop();
			}
		}
		else {
			maxq.push(num);
		}
	}
}