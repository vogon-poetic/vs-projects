#ifndef FLUID_H
#define FLUID_H

#include <string>
#include "GenPoint.h"
#include "Color.h"

using namespace std;

class Fluid
{
private:
	GenPoint start;
	GenPoint end;
	string fluidName;

public:
	Fluid();
	void setStart(GenPoint start);
	void setEnd(GenPoint end);
	void setFluidName(string name);
	GenPoint getStart();
	GenPoint getEnd();
	Color getColor();
	string getFluidName();
};

#endif
