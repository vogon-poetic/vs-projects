#include <iostream>
#include <cmath>
#include "graph1.h"
#include "Container.h"

Container::Container()
{
	this->setPosition(GenPoint(0,0));
	this->setHeight(0);
	this->setRadius(0);
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
	int red = this->getColor().getRed();
	int blue = this->getColor().getBlue();
	int green = this->getColor().getGreen();

	// Use :: to specify an independent function out of local scope.
	::setColor(drawLine(x, y, x, y + h, 5), red, blue, green); // left
	::setColor(drawLine(x, y+h, x+(2 * r), y+h, 5), red, blue, green); // left
	::setColor(drawLine(x+(2 * r), y+h, x+(2 * r), y, 5), red, blue, green); // left

	// Draw wall and floor
	::setColor(drawRect(0, 0, 50, 400), 200, 200, 200);
	::setColor(drawRect(0, 400, 640, 78), 71, 35, 35);
}
