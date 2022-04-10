#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

struct min {
	bool operator() (int a, int b) {
		return a >= b;
	}
};

struct max {
	bool operator() (int a, int b) {
		return a <= b;
	}
};

std::priority_queue<int> maxq;
std::priority_queue<int, std::vector<int>, std::greater<int>> minq;

int main()
{
	maxq.push(-11000);
	minq.push(11000);
	int num = 0, input = 0, count = 0, mid = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &input);
		if (++count % 2 == 1) {
			if (maxq.top() > input) {
				mid = maxq.top();
				maxq.pop();
				maxq.push(input);
			}
			else if (minq.top() < input) {
				mid = minq.top();
				minq.pop();
				minq.push(input);
			}
			else {
				mid = input;
			}
			printf("%d\n", mid);
		}
		else {
			if (input < mid) {
				maxq.push(input);
				minq.push(mid);
			}
			else {
				maxq.push(mid);
				minq.push(input);
			}
			printf("%d\n", maxq.top());
		}
	}
}