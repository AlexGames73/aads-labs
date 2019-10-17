#pragma once
#include <vector>
using namespace std;

class BinaryHeap
{
private:
	int* list;
	int heapSize;
	int heapCapacity;
	void add(int value);

public:
	void buildHeap(int* a, int size);
	void heapify(int i);
	int max();
	void popMax();
	~BinaryHeap()
	{
		delete[] list;
	}
};

