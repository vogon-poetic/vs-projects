#include <iostream>
#include <cmath>
#include "Color.h" 
#include "graph1.h" 

Color::Color()
{
	this->setColor(0, 0, 0);
}

Color::Color(int r, int g, int b)
{
	this->setColor(r, g, b);
}

void Color::setColor(int r, int g, int b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

int Color::getRed()
{
	return this->r;
}

int Color::getGreen()
{
	return this->g;
}

int Color::getBlue()
{
	return this->b;
}
