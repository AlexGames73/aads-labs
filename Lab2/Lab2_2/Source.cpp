#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
using namespace std;

long long mem[100000] = {};

long long fib(int c) {
	if (mem[c] != 0)
		return mem[c];
	if (c < 2)
		return c;
	mem[c] = fib(c - 2) + fib(c - 1);
	return mem[c];
}

void swap(int* mas, int i, int j) {
	int buf = mas[i];
	mas[i] = mas[j];
	mas[j] = buf;
}

void merge_sort(int* mas, int a, int b) {
	if (b - a <= 1) {
		if (b > a&& mas[a] > mas[b])
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

void bubble_sort(int* mas, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (mas[i] > mas[j])
				swap(mas, i, j);
		}
	}
}

int main() {
	int c;
	cin >> c;
	cout << fib(c);

	int mas1[] = { 9,8,7,6,5,4,3,2,6,5,4,3,2,1 };
	int mas2[] = { 9,8,7,6,5,4,3,2,6,5,4,3,2,1 };

	merge_sort(mas1, 0, 13);
	bubble_sort(mas2, 14);
}