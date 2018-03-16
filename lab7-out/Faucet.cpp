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
}

void Faucet::turnOff() {
	// draw line from end of faucet to the middle bottom of container
}

void Faucet::setPosition(GenPoint upper) {
	this->pos = upper;
}

GenPoint Faucet::getPosition() {
	return (this->pos);
}

void Faucet::setFluid(Fluid fluid) {
	this->fluid = fluid;
}

Fluid Faucet::getFluid() {
	return (this->fluid);
}

void Faucet::draw() {

}
