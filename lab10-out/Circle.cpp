#include "Circle.h"
#include "graph1.h"

double const Circle::PI = 3.14159;

Circle::Circle()
{
	radius = 0;
	center = GenPoint(0, 0);
}
Circle::Circle(GenPoint center, int radius, Color c)
{
	setCenter(center);
	setRadius(radius);
	this->color = c;
}
void Circle::setCenter(GenPoint center)
{
	this->center = center;
}
void Circle::setRadius(int radius)
{
	this->radius = radius;
}
double Circle::getPerimeter()
{
	return (2 * PI * radius);
}
double Circle::getArea()
{
	return (PI * radius * radius);
}
void Circle::print()
{
	gout << setPos(0, 400) << "-----------------------------------------------------------------------------------" << endg;
	gout << setPos(200, 405) << "Shape info follows for: Quadrilateral" << endg;
	gout << setPos(200, 420) << "Center Point: (" << center.getX() << "," << center.getY() << ")" << endg;
	gout << setPos(200, 435) << "Radius: " << this->radius << endg;
	gout << setPos(200, 450) << "Perimeter: " << getPerimeter() << endg;
}
void Circle::draw()
{
	int r = color.getRed();
	int g = color.getGreen();
	int b = color.getBlue();
	::setColor(::drawCircle(radius, center.getX(), center.getY()), r,g,b);
}
