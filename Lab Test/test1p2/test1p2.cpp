#include <iostream>
#include "graph1.h"

using namespace std;

void getData(int* no_points, int* x, int* y, int* r, int* g, int* b);
int* drawPolyLine(int *x, int *y, int no_points);
void colorPolyLine(int* objects, int no_points, int r, int g, int b);

int main(void)
{
	char repeat;
	displayGraphics();

	do {
		int no_points = 0;
		int r, g, b;
		int x[10] = { -1 };
		int y[10] = { -1 };
		int* objects = NULL;

		getData(&no_points, x, y, &r, &g, &b);
		objects = drawPolyLine(x, y, no_points);
		colorPolyLine(objects, no_points, r, g, b);

		cout << "Would you like to run the program again? (Y|N): ";
		cin >> repeat;

		delete[] objects;
	} while (repeat == 'y' || repeat == 'Y');

	return 0;
}

void getData(int* no_points, int* x, int* y, int* r, int* g, int* b)
{
	do {
		cout << "Enter # of points: ";
		cin >> *no_points;
		cin.ignore();
	} while (*no_points > 10 || *no_points < 3);

	cout << "Enter r/g/b color: ";
	cin >> *r >> *g >> *b;
	cin.ignore();

	for (int i = 0; i < *no_points; ++i) {
		cout << "Enter x/y coord for Point #" << i+1 << ": ";
		cin >> x[i] >> y[i];
		cin.ignore();
	}
}

int* drawPolyLine(int *x, int *y, int no_points)
{
	int* objects = new int[no_points];

	for (int i = 1; i < no_points; ++i) {
		objects[i-1] = drawLine(x[i - 1], y[i - 1], x[i], y[i], 2);
	}

	return objects;
}

void colorPolyLine(int* objects, int no_points, int r, int g, int b)
{
	for (int i = 0; i < no_points - 1; ++i) {
		setColor(objects[i], r, g, b);
	}

}
