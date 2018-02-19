#include <iostream>
#include "graph1.h"

using namespace std;

void getData(int* no_stairs, int* r, int* g, int* b);
void displayStairs(int no_stairs, int r, int g, int b);

int main(void)
{
	char repeat;

	do {
		int no_stairs, r, g, b;
		getData(&no_stairs, &r, &g, &b);
		displayGraphics();
		displayStairs(no_stairs, r, g, b);
		cout << "Would you like to repeat the program? (Y|N): ";
		cin >> repeat;
	} while (repeat == 'y' || repeat == 'Y');

	
	return 0;
}

void getData(int* no_stairs, int* r, int* g, int* b)
{
	do {
		cout << "Enter # of stairs to display: ";
		cin >> *no_stairs;
		cin.ignore();
	} while (*no_stairs > 6 || *no_stairs < 3);

	cout << "Enter r/g/b color: ";
	cin >> *r >> *g >> *b;
	cin.ignore();
}

void displayStairs(int no_stairs, int r, int g, int b)
{
	int* stairs = new int[no_stairs];
	int x = 0, y = 400;

	for (int i = 0; i < no_stairs; ++i) {
		stairs[i] = drawRect((x + i * 50), (y - i * 20), 100, 20);

		if (i % 2) 
			setColor(stairs[i], r, g, b);
		else 
			setColor(stairs[i], 128, 128, 128);
	}

	delete[] stairs;
}
