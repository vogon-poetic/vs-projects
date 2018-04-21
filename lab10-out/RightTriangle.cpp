#include "RightTriangle.h"
#include "graph1.h"
RightTriangle::RightTriangle()
{
	GenPoint zero = GenPoint(0, 0);
	setPoints(zero, zero, zero);
}
RightTriangle::RightTriangle(GenPoint vertex, int height, int base, Color color)
{
	c = vertex;
	a = GenPoint(vertex.getX(), vertex.getY() - height);
	b = GenPoint(vertex.getX() + base, vertex.getY());
	this->color = color;
}
void RightTriangle::print()
{
	gout << setPos(0, 15) << "Right Triangle" << endg;
	Triangle::print();
}
