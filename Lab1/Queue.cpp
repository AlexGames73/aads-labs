#include <stdio.h>

template<typename T>
class Queue
{
private:
	T* values = new T[1];
	int capacity = 1;
	int headIndex = 0;
	int tailIndex = 0;

public:
	int size = 0;

	void Push(T elem);
	T Pop();
	bool isEmpty();

	void debug() {
		if (isEmpty()) {
			for (int i = 0; i < capacity; i++) {
				printf("_");
				if (i != capacity - 1)
					printf(", ");
			}
			printf("\n");
			return;
		}
		for (int i = 0; i < capacity; i++) {
			if (headIndex >= tailIndex && (i < tailIndex || i >= headIndex))
				printf("%d", values[i]);
			else if (headIndex < tailIndex && (i < tailIndex && i >= headIndex))
				printf("%d", values[i]);
			else
				printf("_");
			if (i != capacity - 1)
				printf(", ");
		}
		printf("\n");
	}
};

template<typename T>
void Queue<T>::Push(T elem)
{
	if (size == capacity) {
		T* buffer = new T[capacity * 2];
		int ind = 0;
		for (int i = headIndex; i < capacity; i++)
			buffer[ind++] = values[i];
		for (int i = 0; i < tailIndex; i++)
			buffer[ind++] = values[i];
		delete[] values;
		values = buffer;
		capacity *= 2;
		headIndex = 0;
		tailIndex = ind;
	}
	values[tailIndex] = elem;
	tailIndex = (tailIndex + 1) % capacity;
	size++;
}

template<typename T>
T Queue<T>::Pop()
{
	if (isEmpty())
		throw "Queue is empty";
	T elem = values[headIndex];
	headIndex = (headIndex + 1) % capacity;
	size--;
	return elem;
}

template<typename T>
bool Queue<T>::isEmpty()
{
	return size == 0;
}
