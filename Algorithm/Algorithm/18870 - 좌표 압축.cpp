#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

struct data {
	int num;
	int sequence;
	data(int num, int sequence) : num(num), sequence(sequence) {}
};

std::vector<data> vec;
int N, input, press, now;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		vec.push_back(data(input, i));
	}
	std::sort(vec.begin(), vec.end(), [](data a, data b) {
		return a.num < b.num;
		});
	now = 0, press = 0;
	now = vec[0].num;
	for (auto& elem : vec) {
		if (elem.num == now) {
			elem.num = press;
		}
		else {
			now = elem.num;
			elem.num = ++press;
		}
	}
	std::sort(vec.begin(), vec.end(), [](data a, data b) {
		return a.sequence < b.sequence;
		});
	for (auto& elem : vec) {
		printf("%d ", elem.num);
	}
}