#include <iostream>
#include <string>
#include "GenRectangle.h"
#include "graph1.h"
using namespace std;

int main(void) {
	GenRectangle rect1;
	GenRectangle rect2;
	int x, y, w, h;

	displayGraphics();
	
	rect1.draw();
	gout << setPos(rect1.getX(), (rect1.getY() + rect1.getHeight() + 12)) << "rect1" << endg;
	gout << setPos(rect1.getX(), (rect1.getY() + rect1.getHeight() + 24)) << "Area: " << rect1.getArea() << endg;
	gout << setPos(rect1.getX(), (rect1.getY() + rect1.getHeight() + 36)) << "Perimeter: " << rect1.getPerimeter() << endg;
	gout << setPos(rect1.getX(), (rect1.getY() + rect1.getHeight() + 48)) << "Type: " << rect1.getType() << endg;

	// Get info about rect2
	cout << "Enter x/y coordinate: ";
	cin >> x >> y;
	cin.ignore();

	cout << "Enter width for rectangle: ";
	cin >> w;
	cin.ignore();

	cout << "Enter height for rectangle: ";
	cin >> h;
	cin.ignore();
	
	rect2.setX(x);
	rect2.setY(y);
	rect2.setWidth(w);
	rect2.setHeight(h);

	// Display rect 2
	rect2.draw();
	gout << setPos(rect2.getX(), (rect2.getY() + rect2.getHeight() + 12)) << "rect2" << endg;
	gout << setPos(rect2.getX(), (rect2.getY() + rect2.getHeight() + 24)) << "Area: " << rect2.getArea() << endg;
	gout << setPos(rect2.getX(), (rect2.getY() + rect2.getHeight() + 36)) << "Perimeter: " << rect2.getPerimeter() << endg;
	gout << setPos(rect2.getX(), (rect2.getY() + rect2.getHeight() + 48)) << "Type: " << rect2.getType() << endg;

	return 0;
}