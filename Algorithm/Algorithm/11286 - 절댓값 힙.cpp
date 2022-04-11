#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

struct data {
	int num;
	int abs;
	data(int num, int abs) : num(num), abs(abs) {}
};

struct comp {
	bool operator() (data a, data b) {
		if (a.abs == b.abs) {
			return a.num > b.num;
		}
		else {
			return a.abs > b.abs;
		}
	}
};

std::priority_queue<data, std::vector<data>, comp> absq;

int count, num;

int main()
{
	scanf("%d", &count);
	for (int i = 0; i < count; ++i) {
		scanf("%d", &num);
		if (num == 0) {
			if (absq.size() == 0) {
				printf("0\n");
			}
			else {
				printf("%d\n", absq.top().num);
				absq.pop();
			}
		}
		else {
			absq.push(data(num, (int)fabs(num)));
		}
	}
}