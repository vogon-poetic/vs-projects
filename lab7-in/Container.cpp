#include <iostream>
#include <cmath>
#include "graph1.h"
#include "Container.h"

Container::Container()
{
	this->setPosition(GenPoint(0,0));
}

void Container::setPosition(GenPoint pos)
{
	this->pos = pos;
}

void Container::setRadius(int radius)
{
	this->radius = radius;
}

void Container::setHeight(int height)
{
	this->height = height;
}

void Container::setColor(Color color)
{
	this->color = color;
}

GenPoint Container::getPosition()
{
	return (this->pos);
}

int Container::getRadius()
{
	return (this->radius);
}

int Container::getHeight()
{
	return (this->height);
}

Color Container::getColor()
{
	return (this->color);
}

void Container::draw()
{
	int thickness = 5;
	int x = this->pos.getX();
	int y = this->pos.getY();
	int h = this->getHeight();
	int r = this->getRadius();

	drawLine(x, y, x, y + h, 5); // left
	drawLine(x, y+h, x+(2 * r), y+h, 5); // bottom
	drawLine(x+(2 * r), y+h, x+(2 * r), y, 5); // right
}
