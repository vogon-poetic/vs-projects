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

/*	1. draw the container
	2. setup faucet & fluid (done within setFaucet)
	3. draw the faucet
*/
void Simulation::draw() {
	// 1. Draw the container
	this->container.draw();

	// 2. Set the starting point of fluid and waterRate
	this->setFaucet(this->faucet);

	// 3. draw the faucet
	this->faucet.draw();
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

void Simulation::setFaucet(Faucet faucet) {
	int y = 12;
	int r = this->getContainer().getRadius();
	this->faucet.setPosition(GenPoint(r, y));
	this->faucet.setFluid(faucet.getFluid());

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
	double pi = 3.14159;
	int y = 12;
	int r = this->getContainer().getRadius();
	int h = this->getContainer().getHeight();
	double vol = pi * (r*r)*h;
	int flowrate = this->getWaterRate();
	GenPoint fluid_pos = this->getContainer().getPosition();
	int fx = 0, fy = 0;
	fx = fluid_pos.getX();
	fy = fluid_pos.getY() + this->container.getHeight();

	// turn on
	this->faucet.turnOn();

	// to convert from waterRate (gpm) into a useful unit:
	// (mm^3)/s = (3785411.78 * waterRate)/60 
	// where 1mm = 1px
	double dv = (3785411.78 * flowrate) / 60;
	double dh = dv / (pi * r * r);
	double height = 0;
	GenPoint endp = this->faucet.getFluid().getEnd();

	// begin the actual draw loop 
	for (height = 0; height <= this->container.getHeight();) {
		dh = dv / (pi * r * r);
		if (dh > 0) {
			height += (int)floor(dh);
			::setColor(drawRect(fx, fy - height, 2 * r, height), 0, 0, 255);

			Sleep(100);
		}
		else {
			do {
				height += dh;
				Sleep(100);
			} while (height <= 1);
		}
	}
	
	Fluid f = this->faucet.getFluid();
	f.setEnd(GenPoint(endp.getX(), endp.getY() - height));
	this->faucet.setFluid(f);
	this->faucet.turnOff();

	return;
}
