#include <iostream>
#include "graph1.h"

using namespace std;

class FilledCircle
{
private:
	int x;
	int y;
	int radius;

public:
	FilledCircle();
	bool setX(int x_val);
	int getX();
	bool setY(int y_val);
	int getY();
	bool setRadius(int r_val);
	int getRadius();
	void draw();
};

FilledCircle::FilledCircle()
{
	//Set private data fields to default values
	setX(0);
	setY(0);
	setRadius(15);
}

bool FilledCircle::setX(int x_val)
{
	//Implement rules for x_val when out of range  
	if (x_val < 0) {
		x = 0;
		return false;
	} else if (x_val >= 640) {
		x = 639;
		return false;
	}

	return true;
}

int FilledCircle::getX()
{
	return x;
}

bool FilledCircle::setY(int y_val)
{
	//Implement rules for setting the y-coord
	if (y_val < 0) {
		y = 0;
		return false;
	} else if (y_val >= 480) {
		y = 479;
		return false;
	}

	return true;
}

int FilledCircle::getY()
{
	return y;
}

bool FilledCircle::setRadius(int r_val)
{
	//Implement rule for setting the radius
	if (r_val <= 0) {
		radius = 1;
		return false;
	} else if (r_val > 30) {
		radius = 30;
		return false;
	}

	return true;
}

int FilledCircle::getRadius()
{
	return radius;
}

void FilledCircle::draw()
{
	//Draw the filled circle
	for (int i = 0; i <= getRadius(); ++i) 
		drawCircle(i, getY(), getX());
}

int main()
{
	//Variable Declaration/Initialization
	int i = 0;
	int x = 0;
	int y = 0;
	int radius = 0;

	FilledCircle circle1;

	char repeat;

	//Display the Graphics
	displayGraphics();

	do
	{
		//Prompt for the x/y coordinates
		cout << "Enter x/y coords: ";
		cin >> x >> y;

		//Prompt for the radius
		cout << "Enter radius: ";
		cin >> radius;

		//Set the x coord for circle1 – display message if x is out of range
		if (!circle1.setX(x)) {
			cout << "Error: x-value is out of range." << endl;
		}

		//Set the y coord for circle1 – display message if y is out of range
		if (!circle1.setY(y)) {
			cout << "Error: y-value is out of range." << endl;
		}

		//Set the radius for cirle1 – display message if radius is out of range
		if (!circle1.setRadius(radius)) {
			cout << "Error: radius is out of range." << endl;
		}

		//Draw the circle
		circle1.draw();

		//Display the coordinate info, radius info under the circle along with the 
		gout << setPos(circle1.getX(), circle1.getY() + 15) 
			<< "(" << circle1.getX() << "," << circle1.getY() << ")" << endg;
		gout << setPos(circle1.getX(), circle1.getY() + 30)
			<< "Radius: " << circle1.getRadius() << endg;

		cout << "\nWould you like to repeat? (y/n): ";
		cin >> repeat;

	} while (repeat == 'y' || repeat == 'Y');

	return 0;
}
