#include "Color.h"
#include "graph1.h"
#include <math.h>

static double mag(Color c) {
	int red = c.getRed();
	int green = c.getGreen();
	int blue = c.getBlue();
	
	double magnitude = sqrt((double)(red ^ 2 + green ^ 2 + blue ^ 2));
	return magnitude;
}

Color::Color() {
	this->setColor(100, 100, 100);
}

Color::Color(int r, int g, int b) {
	this->setColor(r, g, b);
}
void Color::setColor(int r, int g, int b) {
	this->r = r;
	this->g = g;
	this->b = b;
}
int Color::getRed() {
	return(r);
}
int Color::getGreen() {
	return(g);
}
int Color::getBlue() {
	return(b);
}
Color Color::operator+(Color right) {
	int red = r + right.getRed();
	int green = g + right.getGreen();
	int blue = b + right.getBlue();
	
	if (red > 255) 
		red = 255;
	if (green > 255)
		green = 255;
	if (blue > 255)
		blue = 255;
	
	return(Color(red, green, blue));
}
Color Color::operator-(Color right) {
	int red = r - right.getRed();
	int green = g - right.getGreen();
	int blue = b - right.getBlue();

	if (red < 0)
		red = 0;
	if (green < 0)
		green = 0;
	if (blue < 0)
		blue = 0;

	return(Color(red, green, blue));
}
Color Color::operator/(int right) {
	int red = r / right;
	int green = g / right;
	int blue = b / right;

	return(Color(red, green, blue));
}
Color Color::operator*(int right) {
	int red = r * right;
	int green = g * right;
	int blue = b * right;

	return(Color(red, green, blue));
}
bool Color::operator==(Color right) {
	if (this->getRed() == right.getRed() &&
		this->getGreen() == right.getGreen() &&
		this->getBlue() == right.getBlue()) {
		return true;
	} else {
		return false;
	}
}
bool Color::operator!=(Color right) {
	if (this->getRed() == right.getRed() &&
		this->getGreen() == right.getGreen() &&
		this->getBlue() == right.getBlue()) {
		return false;
	} else {
		return true;
	}
}
void Color::operator=(Color right) {
	int red = right.getRed();
	int green = right.getGreen();
	int blue = right.getBlue();
	this->setColor(red, green, blue);
}
Color Color::operator!() {
	return Color(255 - this->getRed(),
		255 - this->getGreen(),
		255 - this->getBlue());
}
Color Color::operator++() {
	r += 25;
	g += 25;
	b += 25;

	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;

	return (*this);
}
Color Color::operator++(int dummy) {
	Color temp = *this;
	++*this;
	return(temp);
}
Color Color::operator--() {
	r -= 25;
	g -= 25;
	b -= 25;
	
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;

	return *this;
}
Color Color::operator--(int dummy) {
	Color temp = *this;
	--*this;
	return temp;
}
bool Color::operator<(Color right) {
	if (mag(*this) < mag(right)) {
		return true;
	}

	return false;
}
bool Color::operator>(Color right) {
	if (mag(*this) > mag(right)) {
		return true;
	}

	return false;
}
void Color::draw(int x, int y, int w, int h) {
	::setColor(drawRect(x, y, w, h));
}
