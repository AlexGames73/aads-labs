#include "Integer.h"
#include <sstream>

int Integer::hashCode()
{
	return value;
}

bool Integer::compare(Object* other)
{
	return hashCode() == other->hashCode();
}

string Integer::toString()
{
	ostringstream str;
	str << value;
	return str.str();
}
