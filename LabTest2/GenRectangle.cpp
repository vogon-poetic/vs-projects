#include <iostream>
#include <string>
#include "GenRectangle.h"
#include "graph1.h"
using namespace std;

GenRectangle::GenRectangle() {
	this->x = 100;
	this->y = 25;
	this->width = 20;
	this->height = 30;
}

int GenRectangle::getWidth()
{
	return (this->width);
}

int GenRectangle::getHeight()
{
	return (this->height);
}

int GenRectangle::getX()
{
	return (this->x);
}

int GenRectangle::getY()
{
	return (this->y);
}

int GenRectangle::getArea()
{
	return (this->x * this->y);
}

int GenRectangle::getPerimeter()
{
	return ((this->x * 2) + (this->y * 2));
}

void GenRectangle::setWidth(int width)
{
	if (width < 1) {
		this->width = 1;
	}
	else if (width > 50) {
		this->width = 50;
	}
	else {
		this->width = width;
	}
}

void GenRectangle::setHeight(int height)
{
	if (height < 1) {
		this->height = 1;
	}
	else if (height > 50) {
		this->height = 50;
	}
	else {
		this->height = height;
	}
}

void GenRectangle::setX(int x)
{
	if (x < 100) {
		this->x = 100;
	}
	else if (x > 539) {
		this->x = 539;
	}
	else {
		this->x = x;
	}
}

void GenRectangle::setY(int y)
{
	if (y < 25) {
		this->y = 25;
	}
	else if (y > 455) {
		this->y = 455;
	}
	else {
		this->y = y;
	}
}

string GenRectangle::getType()
{
	int area = this->getArea();
	if (area < 300 || area < 0) {
		return "SMALL_RECTANGLE";
	}
	else if (area >= 300 && area < 1000) {
		return "MIDDLE_RECTANGLE";
	}
	else if (area >= 1000) {
		return "LARGE_RECTANGLE";
	}
}

void GenRectangle::draw()
{
	string type = this->getType();
	int x, y, width, height;
	x = this->getX();
	y = this->getY();
	width = this->getWidth();
	height = this->getHeight();

	if (type == "SMALL_RECTANGLE") {
		setColor(drawRect(x, y, width, height), 255, 0, 0);
		setColor(drawRect(x+2, y+2, width-4, height-4), 0, 0, 0);
	}
	else if (type == "MIDDLE_RECTANGLE") {
		setColor(drawRect(x, y, width, height), 0, 255, 0);
		setColor(drawRect(x+2, y+2, width-4, height-4), 0, 0, 0);
	}
	else if (type == "LARGE_RECTANGLE") {
		int outer = drawRect(x, y, width, height);
		int inner = drawRect(x + 2, y + 2, width - 4, height - 4);
		setColor(outer, 0, 0, 255);
		setColor(inner, 0, 0, 0);
	}
}
