#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int count, last, able;
int same = -1, start;
int data[110000][2];
int sorted[110000][2];

void merge(int data[][2], int start, int mid, int end, int looked) {
	int i = start, j = mid + 1, k = start;
	while (i <= mid && j <= end) {
		if (data[i][looked] <= data[j][looked]) {
			sorted[k][0] = data[i][0];
			sorted[k][1] = data[i][1];
			i++;
		}
		else {
			sorted[k][0] = data[j][0];
			sorted[k][1] = data[j][1];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (int t = j; t <= end; t++) {
			sorted[k][0] = data[t][0];
			sorted[k][1] = data[t][1];
			k++;
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			sorted[k][0] = data[t][0];
			sorted[k][1] = data[t][1];
			k++;
		}
	}
	for (int t = start; t <= end; t++) {
		data[t][0] = sorted[t][0];
		data[t][1] = sorted[t][1];
	}
}

void merge_sort(int data[][2], int start, int end, int looked) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(data, start, mid, looked);
		merge_sort(data, mid + 1, end, looked);
		merge(data, start, mid, end, looked);
	}
}

int main()
{
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		scanf("%d %d", &data[i][0], &data[i][1]);
	}
	merge_sort(data, 0, count - 1, 1);
	for (int i = 0; i < count; i++) {
		if (i == 0) {
			same = data[i][1];
			start = i;
		}
		else if (data[i][1] != same) {
			merge_sort(data, start, i - 1, 0);
			same = data[i][1];
			start = i;
		}
		else {
			continue;
		}
	}
	if (data[start][1] == data[count - 1][1]) {
		merge_sort(data, start, count - 1, 0);
	}
	for (int i = 0; i < count; i++) {
		printf("%d %d\n", data[i][0], data[i][1]);
	}
	for (int i = 0; i < count; i++) {
		if (last <= data[i][0]) {
			able++;
			last = data[i][1];
		}
	}
	printf("%d", able);
}