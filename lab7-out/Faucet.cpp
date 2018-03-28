#include "Faucet.h"
#include "Fluid.h"
#include "GenPoint.h"
#include "Color.h"
#include "graph1.h"

// Default constructor
Faucet::Faucet() {
	this->setFluid(Fluid());
	this->setPosition(GenPoint(0, 0));
}

void Faucet::setPosition(GenPoint upper) {
	this->pos = upper;
}

GenPoint Faucet::getPosition() {
	return this->pos;
}

void Faucet::setFluid(Fluid fluid) {
	this->fluid = fluid;
	int faucetx = this->getPosition().getX();
	int faucety = this->getPosition().getY();
	int startx = faucetx + 55;
	int starty = faucety + 55;

	this->fluid.setStart(GenPoint(startx, starty));
	this->fluid.setEnd(GenPoint(startx, 396)); // 
}

Fluid Faucet::getFluid() {
	return (this->fluid);
}

void Faucet::draw() {
	int x = this->getPosition().getX();
	int y = this->getPosition().getY();
	displayBMP("faucet.bmp", x, y);
	::setColor(drawLine(50, 50, x, 50, 9), 128, 128, 128);
}

void Faucet::turnOn() {
	GenPoint start = this->fluid.getStart();
	GenPoint end = this->fluid.getEnd();

	// draw a blue stream from faucet to base of container
	::setColor(drawLine(start.getX(), start.getY(), end.getX(), end.getY(), 3), 0, 0, 255);

	// Begin filling up the container
}

void Faucet::turnOff() {
	GenPoint start = this->fluid.getStart();
	GenPoint end = this->fluid.getEnd();

	::setColor(drawLine(start.getX(), start.getY(), end.getX(), end.getY(), 3), 0, 0, 0);
}

