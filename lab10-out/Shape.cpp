#include "Shape.h"
#include "graph1.h"

Shape::Shape() //Default Constructor - sets color to (0,0,0)
{
	this->color.setColor(0, 0, 0);
}
Color Shape::getColor()  //Getter for Color
{
	return this->color;
}
void Shape::setColor(Color color) //Setter for Color
{
	int r = color.getRed();
	int g = color.getGreen();
	int b = color.getBlue();

	this->color.setColor(r, g, b);
}

