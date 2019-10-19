#include <iostream>
using namespace std;

void hanoi(int n, int from, int to, int temp) {
	if (n == 1) {
		cout << from << " " << to << endl;
		return;
	}
	hanoi(n - 1, from, temp, to);
	cout << from << " " << to << endl;
	hanoi(n - 1, temp, to, from);
}

int main() {
	hanoi(6, 0, 2, 1);
}