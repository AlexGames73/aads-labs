#include "HashTableLinear.h"
#include "HashTableChain.h"
#include "Integer.h"
#include <iostream>
using namespace std;

int main() {
	HashTableLinear htl(1000);
	htl.add(new Integer(15434));
	cout << htl.contains(new Integer(15434)) << endl;
	cout << htl.contains(new Integer(434)) << endl;
	htl.add(new Integer(434));
	cout << htl.contains(new Integer(434)) << endl;
	htl.remove(new Integer(434));
	cout << htl.contains(new Integer(434)) << endl;
}