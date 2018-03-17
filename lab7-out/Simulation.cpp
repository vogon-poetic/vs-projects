#include <iostream>
#include "graph1.h"
#include "Faucet.h"
#include "Simulation.h"
#include "Container.h"
#include "Color.h"
using namespace std;

Simulation::Simulation() {
	this->container.setColor(Color(0, 0, 0));
	this->container.setPosition(GenPoint(0, 0));
	this->container.setRadius(0);
}

void Simulation::draw() {
	this->container.draw();
	this->setFaucet(this->faucet);
	this->start();
}

void Simulation::setContainer(Container container) {
	this->container.setColor(container.getColor());
	this->container.setHeight(container.getHeight());
	this->container.setPosition(container.getPosition());
	this->container.setRadius(container.getRadius());
}

Container Simulation::getContainer() {
	return this->container;
}

// suggested x-coord = (radius - 64) + 50
// suggested y-coord = 12
void Simulation::setFaucet(Faucet faucet) {
	int x = (this->getContainer().getRadius() - 64) + 50;
	int y = 12;
	this->faucet.setFluid(faucet.getFluid());
	this->faucet.setPosition(GenPoint(x, y));
}

Faucet Simulation::getFaucet() {
	return this->faucet;
}

int Simulation::getWaterRate() {
	return this->waterRate;
}

void Simulation::setWaterRate(int waterRate) {
	this->waterRate = waterRate;
}

void Simulation::start() {
	this->faucet.turnOn();
	this->faucet.turnOff();
}
