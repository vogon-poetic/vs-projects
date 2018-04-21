#include "graph1.h"
#include "Trapezoid.h"

Trapezoid::Trapezoid() {}
Trapezoid::Trapezoid(GenPoint a, GenPoint b, GenPoint c, GenPoint d, Color color)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;

	this->setColor(color);
}
void Trapezoid::setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d)
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
	double ds = sqrt(dx*dx + dy * dy);

	return ds;
}
double Trapezoid::getArea()
{
	double b1 = distance(a, b);
	double b2 = distance(c, d);
	double h = c.getY() - a.getY();
	double area = 0.5 * (b1 + b2) * (double) h;

	return area;
}
void Trapezoid::print()
{
	gout << setPos(0, 15) << "Trapezoid Information" << endg;
	gout << setPos(0, 30) << "Area: " << getArea() << endg;
}
