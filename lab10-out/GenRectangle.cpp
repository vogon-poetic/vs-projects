#include "graph1.h"
#include "Quadrilateral.h"
#include "GenRectangle.h"

GenRectangle::GenRectangle() {}
GenRectangle::GenRectangle(GenPoint ul, GenPoint lr, Color c)
{
	setPoints(ul, lr);
	setColor(c);
}
void GenRectangle::setPoints(GenPoint ul, GenPoint lr)
{
	int ulx = ul.getX();
	int uly = ul.getY();
	int lrx = lr.getX();
	int lry = lr.getY();

	this->a = ul;
	this->b.setPoint(lrx, uly);
	this->c = lr;
	this->d.setPoint(ulx, lry);
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
double GenRectangle::getArea()
{
	double l = distance(a, b);
	double w = distance(b, c);

	return (l * w);
}
void GenRectangle::print()
{
	gout << setPos(0, 15) << "Rectangle Information" << endg;
	gout << setPos(0, 30) << "Area: " << getArea() << endg;
	Quadrilateral::print();
}
