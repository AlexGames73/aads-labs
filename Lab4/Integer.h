#pragma once
#include "Object.h"

class Integer :
	public Object
{
private:
	int value;
public:
	Integer(int val) {
		value = val;
	}
	int hashCode();
	bool compare(Object* other);
	string toString();
	int toInt() {
		return value;
	}
};
