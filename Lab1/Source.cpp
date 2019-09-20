#include <stdio.h>
#include "Queue.cpp"
using namespace std;

void swap(int* mas, int i, int j) {
	int buf = mas[i];
	mas[i] = mas[j];
	mas[j] = buf;
}

void shaker_sort(int* mas, int length) {
	int left = 0;
	int right = length - 1;
	while (left < right) {
		for (int i = left; i < right; i++) {
			if (mas[i] > mas[i + 1])
				swap(mas, i, i + 1);
		}
		right--;

		for (int i = right; i > left; i--) {
			if (mas[i - 1] > mas[i])
				swap(mas, i - 1, i);
		}
		left++;
	}
}

void merge_sort(int* mas, int a, int b) {
	if (b - a <= 1) {
		if (b > a && mas[a] > mas[b])
			swap(mas, a, b);
		return;
	}
	merge_sort(mas, a, a + (b - a) / 2 - 1);
	merge_sort(mas, a + (b - a) / 2, b);
	for (int i = a; i < a + (b - a) / 2; i++) {
		for (int j = b; j >= a + (b - a) / 2; j--) {
			if (mas[i] > mas[j])
				swap(mas, i, j);
		}
	}
}

int main() {
	Queue<int> q;
	q.debug();
	q.Push(1);
	q.debug();
	q.Push(2);
	q.debug();
	q.Push(3);
	q.debug();
	q.Pop();
	q.debug();
	q.Push(4);
	q.debug();
	q.Pop();
	q.debug();
	q.Push(5);
	q.debug();
	q.Push(6);
	q.debug();
	q.Push(7);
	q.debug();

	int mas1[] = { 4, 3, 2, 1, 0, 5, 4, 3 };
	int mas2[] = { 4, 3, 2, 1, 0, 5, 4, 3 };

	shaker_sort(mas1, 8);
	merge_sort(mas2, 0, 7);

	printf("shaker sort: ");
	for (int i = 0; i < 7; i++) {
		printf("%d ", mas1[i]);
	}
	printf("\n");

	printf("merge sort: ");
	for (int i = 0; i < 7; i++) {
		printf("%d ", mas2[i]);
	}
	printf("\n");
}