#include <iostream>
#include "graph1.h"
#include "ColorFilledCircle.h"
#include "ColorCircle.h"

ColorCircle::ColorCircle()
{
  setR(200);
  setG(200);
  setB(200);

}

ColorCircle::~ColorCircle()
{
  //Nothing to cleanup yet
}

void ColorCircle::setR(int r)
{
  this->r = r;
}

void ColorCircle::setG(int g)
{
  this->g = g;
}

void ColorCircle::setB(int b)
{
  this->b = b;
}

int ColorCircle::getR()
{
  return r;
}

int ColorCircle::getG()
{
  return g;
}

int ColorCircle::getB()
{
  return b;
}

void ColorCircle::draw()
{
  int obj_no = drawCircle(radius,x,y);
  setColor(obj_no,r,g,b);
}

void ColorCircle::print()
{
  Circle::print();
  gout << setPos(x,y+radius+75) 
	   << "Color: " << r << "," << g << "," << b << endg;
}

