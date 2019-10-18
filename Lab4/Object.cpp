#include "Object.h"

int Object::hashCode()
{
	return 0;
}

bool Object::compare(Object other)
{
	return hashCode() == other.hashCode();
}

string Object::toString()
{
	return "Object";
}
