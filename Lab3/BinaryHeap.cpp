#include "BinaryHeap.h"


void BinaryHeap::buildHeap(int* a, int size)
{
	list = new int[size];
	for (int i = 0; i < size; i++)
		list[i] = a[i];
	heapSize = size;
	heapCapacity = size * 2;
	for (int i = heapSize / 2; i >= 0; i--)
		heapify(i);
}


void BinaryHeap::heapify(int i)
{
	while (true) {
		int leftChild = 2 * i + 1;
		int rightChild = 2 * i + 2;
		int largestChild = i;
		if (leftChild < heapSize && list[leftChild] > list[largestChild])
			largestChild = leftChild;
		if (rightChild < heapSize && list[rightChild] > list[largestChild])
			largestChild = rightChild;
		if (largestChild == i)
			break;
		swap(list[i], list[largestChild]);
		i = largestChild;
	}
}


void BinaryHeap::add(int value)
{
	if (heapSize == heapCapacity) {
		heapCapacity *= 2;
		int* temp = new int[heapCapacity];
		for (int i = 0; i < heapSize; i++)
			temp[i] = list[i];
		delete[] list;
		list = temp;
	}
	list[heapSize++] = value;
	int i = heapSize - 1;
	int parent = (i - 1) / 2;

	while (i > 0 && list[parent] < list[i]) {
		swap(list[i], list[parent]);
		i = parent;
		parent = (i - 1) / 2;
	}
}


int BinaryHeap::max()
{
	return list[0];
}


void BinaryHeap::popMax()
{
	list[0] = list[heapSize - 1];
	heapSize--;
	heapify(0);
}
