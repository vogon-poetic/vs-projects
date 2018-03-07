#pragma once
#ifndef SIMULATION_H
#define SIMULATION_H

#include "Container.h"

class Simulation
{
private:
	Container container;


public:
	Simulation();
	void setContainer(Container container);
	Container getContainer();
	void draw();
};

#endif
