#pragma once
#include "Object.h"
#include "Integer.h"
#include <vector>
using namespace std;

class HashTableChain
{
private:
	Object*** chains;
	int capacity;
public:
	HashTableChain(int n) {
		capacity = n;
		chains = new Object**[n];
		for (int i = 0; i < n; i++) {
			int subCapacity = 12;
			int subSize = 0;
			chains[i] = new Object*[12];
			chains[i][0] = new Integer(subCapacity);
			chains[i][1] = new Integer(subSize);
		}
	}

	void add(Object* obj);
	bool contains(Object* obj);
	void remove(Object* obj);
};

inline void HashTableChain::add(Object* obj)
{
	Object** subArray = chains[obj->hashCode() % capacity];
	int subCapacity = ((Integer*)(subArray[0]))->toInt();
	int subSize = ((Integer*)(subArray[1]))->toInt();
	if (subCapacity == subSize) {
		Object** temp = new Object*[subCapacity * 2];
		temp[0] = new Integer(subCapacity * 2);
		temp[1] = new Integer(subSize);
		for (int i = 0; i < subSize; i++)
			temp[i + 2] = subArray[i + 2];
		chains[obj->hashCode() % capacity] = temp;
	}
	chains[obj->hashCode() % capacity][subSize + 2] = obj;
	chains[obj->hashCode() % capacity][1] = new Integer(subSize + 1);
}

inline bool HashTableChain::contains(Object* obj)
{
	int objHash = obj->hashCode();
	int i = objHash % capacity;
	for (int j = 0; j < ((Integer*)(chains[i][1]))->toInt(); j++) {
		if (chains[i][j + 2]->hashCode() == objHash)
			return true;
	}
	return false;
}

inline void HashTableChain::remove(Object* obj)
{
	Object** subArray = chains[obj->hashCode() % capacity];
	int subSize = ((Integer*)(subArray[1]))->toInt();
	for (int i = 0; i < subSize; i++) {
		if (subArray[i + 2]->hashCode() == obj->hashCode()) {
			subArray[1] = new Integer(subSize - 1);
			for (int j = i + 1; j < subSize; j++)
				subArray[j + 2 - 1] = subArray[j + 2];
			return;
		}
	}
}
