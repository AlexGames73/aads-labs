#pragma once
#include <string>
using namespace std;
class Object
{
public:
	virtual int hashCode();
	virtual bool compare(Object other);
	virtual string toString();
};

