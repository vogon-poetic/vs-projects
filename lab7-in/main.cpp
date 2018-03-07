#include <iostream>
#include "graph1.h"
#include "Simulation.h"

using namespace std;

int main()
{
	//Variable Declaration/Initialization
	int height = 0;
	int radius = 0;
	int r = 0;
	int b = 0;
	int g = 0;
	char repeat;
	Container container;
	Simulation simulation;

	//Display the graphics
	displayGraphics();

	//Continually simulate

	do
	{
		//Get the Container's radius/height/color (Add Data Validation)
		radius = container.getRadius();
		height = container.getHeight();
		

		//Set the Containers radius/height /color
		//Compute the Container upper left coordinate based on the height
		//Set the Container’s position
		//Hint: 55, 400 - height

		//Set the Container for the Simulation

		//Draw the simulation/container (invoke draw on Simulation)

		//Repeat the simulation?
		cout << "Repeat the simulation (y/n)? ";
		cin >> repeat;

		clearGraphics();
		system("cls");

	} while (repeat == 'y');

	return 0;
}
