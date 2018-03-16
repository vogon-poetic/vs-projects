#include <iostream>
#include "graph1.h"
#include "Simulation.h"

using namespace std;

Simulation::Simulation()
{
}

void Simulation::draw()
{


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
