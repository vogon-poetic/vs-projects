#include <iostream>
#include "graph1.h"
#include "GenPoint.h"

GenPoint::GenPoint()
{
	setPoint(0, 0);
}

GenPoint::GenPoint(int x, int y)
{
	setPoint(x, y);
}
void GenPoint::setPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}
int GenPoint::getX()
{
	return (this->x);
}
int GenPoint::getY()
{
	return (this->y);
}

