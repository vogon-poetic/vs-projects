#include <string>
#include "Fluid.h"
#include "Faucet.h"
#include "GenPoint.h"
#include "Color.h"
#include "graph1.h"

Fluid::Fluid() {
	this->setFluidName("water");
	this->setEnd(GenPoint(0,0));
}

void Fluid::setStart(GenPoint start) {
	this->start = start;
}

void Fluid::setEnd(GenPoint end) {
	this->end = end;
}

void Fluid::setFluidName(string name) {
	this->fluidName = name;
}

GenPoint Fluid::getStart() {
	return this->start;
}

GenPoint Fluid::getEnd() {
	return this->end;
}

Color Fluid::getColor() {
	// TODO
	// what colors should I include besides water?
	return (this->getFluidName() == "water") ? 
				Color(0, 0, 255) : 
				Color(255, 255, 255);
}

string Fluid::getFluidName() {
	return this->fluidName;
}

