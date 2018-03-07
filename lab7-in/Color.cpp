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
	this->r = (r < 0 || r > 255) ? 0 : r;
	this->g = (g < 0 || g > 255) ? 0 : g;
	this->b = (b < 0 || b > 255) ? 0 : b;
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
