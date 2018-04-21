#include "Triangle.h"
#include "graph1.h"
#include <math.h>

Triangle::Triangle()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
}
Triangle::Triangle(GenPoint a, GenPoint b, GenPoint c, Color color)
{
	setPoints(a, b, c);
	this->color = color;
}
void Triangle::setPoints(GenPoint a, GenPoint b, GenPoint c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

// helper function to get distance between two points
static double distance(GenPoint a, GenPoint b)
{
	int x1 = a.getX();
	int y1 = a.getY();
	int x2 = b.getX();
	int y2 = b.getY();

	double dx = (x2 - x1);
	double dy = (y2 - y1);
	double ds = sqrt(dx*dx + dy * dy);

	return ds;
}

double Triangle::getArea()
{
	double s1 = distance(a, b);
	double s2 = distance(b, c);
	double s3 = distance(c, a);

	double s = (s1 + s2 + s3) / 2.0;
	double area = sqrt(s*(s - s1)*(s - s2)*(s - s3));

	return area;
}
double Triangle::getPerimeter()
{
	double perimeter = distance(a, b);
	perimeter += distance(b, c);
	perimeter += distance(c, a);
	
	return perimeter;
}
void Triangle::print()
{
	gout << setPos(0, 400) << "-----------------------------------------------------------------------------------" << endg;
	gout << setPos(200, 405) << "Shape info follows for: Triangle" << endg;
	gout << setPos(200, 420) << "Point a: (" << a.getX() << "," << a.getY() << ")" << endg;
	gout << setPos(200, 435) << "Point b: (" << b.getX() << "," << b.getY() << ")" << endg;
	gout << setPos(200, 450) << "Point c: (" << c.getX() << "," << c.getY() << ")" << endg;
	gout << setPos(200, 465) << "Perimeter: " << getPerimeter() 
		                     << " Area: " << getArea() << endg;
}
static void drawLine(GenPoint a, GenPoint b, Color color)
{
	int red = color.getRed();
	int green = color.getGreen();
	int blue = color.getBlue();
	int x1 = a.getX();
	int y1 = a.getY();
	int x2 = b.getX();
	int y2 = b.getY();

	::setColor(::drawLine(x1, y1, x2, y2, 3), red, green, blue);
}

void Triangle::draw()
{
	drawLine(a, b, color);
	drawLine(b, c, color);
	drawLine(c, a, color);
}
