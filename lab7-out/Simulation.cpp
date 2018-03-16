#include <iostream>
#include "graph1.h"
#include "Simulation.h"

using namespace std;

Simulation::Simulation()
{
	this->container.setColor(Color(0, 0, 0));
	this->container.setPosition(GenPoint(0, 0));
	this->container.setRadius(0);
}

void Simulation::draw()
{
	this->container.draw();
}

void Simulation::setContainer(Container container)
{
	this->container.setColor(container.getColor());
	this->container.setHeight(container.getHeight());
	this->container.setPosition(container.getPosition());
	this->container.setRadius(container.getRadius());
}

Container Simulation::getContainer()
{
	return this->container;
}
