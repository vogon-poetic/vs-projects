#include "Quadrilateral.h"
#include "graph1.h"
#include <math.h>

Quadrilateral::Quadrilateral()
{
	this->a = GenPoint(0, 0);
	this->b = GenPoint(0, 0);
	this->c = GenPoint(0, 0);
	this->d = GenPoint(0, 0);
}
Quadrilateral::Quadrilateral(GenPoint a, GenPoint b, GenPoint c, GenPoint d, Color color)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;

	this->setColor(color);
}
void Quadrilateral::setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

// Helper function to get distance between two points
static double distance(GenPoint a, GenPoint b)
{
	int x1 = a.getX();
	int y1 = a.getY();
	int x2 = b.getX();
	int y2 = b.getY();

	double dx = (x2 - x1);
	double dy = (y2 - y1);
	double ds = sqrt(dx*dx + dy*dy);

	return ds;
}

double Quadrilateral::getPerimeter()
{
	double perimeter = 0;
	perimeter += distance(a, b);
	perimeter += distance(b, c);
	perimeter += distance(c, d);
	perimeter += distance(d, a);
	
	return perimeter;
}
void Quadrilateral::print()
{
	gout << setPos(0, 400) << "-----------------------------------------------------------------------------------" << endg;
	gout << setPos(200, 405) << "Shape info follows for: Quadrilateral" << endg;
	gout << setPos(200, 420) << "Point a: (" << a.getX() << "," << a.getY() << ")" << endg;
	gout << setPos(200, 435) << "Point b: (" << b.getX() << "," << b.getY() << ")" << endg;
	gout << setPos(200, 450) << "Point c: (" << c.getX() << "," << c.getY() << ")" << endg;
	gout << setPos(200, 465) << "Point d: (" << d.getX() << "," << d.getY() << ")" << endg;
	gout << setPos(200, 480) << "Perimeter: " << getPerimeter() << endg;
}

// helper function to draw a line
static void drawLine(GenPoint a, GenPoint b, Color color)
{
	int red = color.getRed();
	int green = color.getGreen();
	int blue = color.getBlue();
	int x1 = a.getX();
	int y1 = a.getY();
	int x2 = b.getX();
	int y2 = b.getY();

	::setColor(::drawLine(x1, y1, x2, y2, 3), red,green,blue);
}

void Quadrilateral::draw()
{
	drawLine(a, b, color);
	drawLine(b, c, color);
	drawLine(c, d, color);
	drawLine(d, a, color);
}
