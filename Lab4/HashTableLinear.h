#pragma once
#include "Object.h"

class HashTableLinear
{
private:
	Object** arr;
	int capacity;
public:
	HashTableLinear(int n) {
		capacity = n;
		arr = new Object*[n];
		for (int i = 0; i < n; i++) {
			arr[i] = 0;
		}
	}
	void add(Object* obj);
	bool contains(Object* obj);
	void remove(Object* obj);
};

inline void HashTableLinear::add(Object* obj)
{
	int i = obj->hashCode() % capacity;
	while (i < capacity && arr[i] != 0)
		i++;
	if (i < capacity)
		arr[i] = obj;
	else {
		HashTableLinear htl(capacity * 2);
		for (int i = 0; i < capacity; i++) {
			if (arr[i] != 0)
				htl.add(arr[i]);
		}
		delete[] arr;
		arr = htl.arr;
		capacity = htl.capacity;
	}
}

inline bool HashTableLinear::contains(Object* obj)
{
	int i = obj->hashCode() % capacity;
	while (i < capacity) {
		if (arr[i] != 0 && arr[i]->hashCode() == obj->hashCode())
			return true;
		i++;
	}
	return false;
}

inline void HashTableLinear::remove(Object* obj)
{
	if (!contains(obj))
		return;
	int i = obj->hashCode() % capacity;
	while (i < capacity) {
		if (arr[i] != 0 && arr[i]->hashCode() == obj->hashCode()) {
			delete arr[i];
			arr[i] = 0;
			return;
		}
		i++;
	}
}
