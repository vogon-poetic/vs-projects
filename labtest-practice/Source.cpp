#include <iostream>
#include <cctype>
#include <string>
#include "graph1.h"
using namespace std;

void getData(int* r, int* g, int* b, int* radius, int* no_circles);
int* drawChain(int radius, int no_circles);
void colorChain(int* objects, int no_circles, int r, int g, int b);
bool digit_string(string buf);

int main(void)
{
	int r, g, b, radius, circles;
	int* objects;
	getData(&r, &g, &b, &radius, &circles);

	displayGraphics();
	objects = drawChain(radius, circles);
	colorChain(objects, circles, r, g, b);
	
	delete[] objects;
	return 0;
}

void getData(int* r, int* g, int* b, int* radius, int* no_circles)
{
	string buf;
	bool valid = true;

	// validate rgb color input
	do {
	PROMPT: 
		cout << "Enter rgb color: ";
		cin >> *r >> *g >> *b;
		cin.ignore();
		
		if (*r < 0 || *r > 255) {
			valid = false;
			goto PROMPT;
		}

		if (*g < 0 || *g > 255) {
			valid = false;
			goto PROMPT;
		}

		if (*b < 0 || *b > 255) {
			valid = false;
			goto PROMPT;
		}

		valid = true;
	} while (!valid);

	do {
		cout << "Enter radius: ";
		getline(cin, buf);
		
		if (digit_string(buf)) {
			*radius = stod(buf);
			if (*radius > 25 || *radius < 15) {
				valid = false;
			} else {
				valid = true;
			}
		} else {
			valid = false;
		}

	} while (!valid);

	do {
		cout << "Enter # of circles: ";
		getline(cin, buf);

		if (digit_string(buf)) {
			*no_circles = stod(buf);
			if (*no_circles > 10 || *no_circles < 3) {
				valid = false;
			} else {
				valid = true;
			}
		}
	} while (!valid);

}

bool digit_string(string buf)
{
	for (int i = 0; buf[i]; ++i) {
		if (!isdigit(buf[i]))
			return false;
	}

	return true;
}

int* drawChain(int radius, int no_circles)
{
	int x = 100, y = 100;
	int* objects = new int[no_circles];
	for (int i = 0; i < no_circles; ++i) {
		objects[i] = drawCircle(radius, x, y);
		x += radius;
	}

	return objects;
}

void colorChain(int* objects, int no_circles, int r, int g, int b)
{
	for (int i = 0; i < no_circles; ++i) {
		if (i % 2 == 0) {
			setColor(objects[i], r, g, b);
		}
	}
}
