#include <iostream>
using namespace std;

int main(void) {
	int a[3] = { 4, 5, 6 };
	int* p = a;

	cout << 0[p + 1] << endl;
	return 0;
}