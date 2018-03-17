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

void Faucet::turnOn() {
	// draw line from end of faucet to the middle bottom of container
	int x = this->getPosition().getX();
	int y = this->getPosition().getY();
	this->fluid.setStart(GenPoint(x, y));

	::setColor(drawLine(x, y, x, y + 400, 3), 0, 0, 255);
}

void Faucet::turnOff() {
	int x = this->getPosition().getX();
	int y = this->getPosition().getY();
	GenPoint endpoint = this->getFluid().getEnd();
	drawLine(x, y, x, endpoint.getY(), 2);
}

void Faucet::setPosition(GenPoint upper) {
	this->start = upper;
}

GenPoint Faucet::getPosition() {
	return this->start;
}

void Faucet::setFluid(Fluid fluid) {
	this->fluid = fluid;
}

Fluid Faucet::getFluid() {
	return (this->fluid);
}

void Faucet::draw() {
	int x = this->getPosition().getX();
	int y = this->getPosition().getY();
	displayBMP("faucet.bmp", x, y);
	::setColor(drawLine(0, 50, x, 50, 2), 128, 128, 128);
}
