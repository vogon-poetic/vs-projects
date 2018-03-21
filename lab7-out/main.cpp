#include <iostream>
#include "graph1.h"
#include "Simulation.h"

using namespace std;

#define DEBUG_BUILD // uncomment for a predefined height/radius/color

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

#ifndef DEBUG_BUILD
		//Get the Container's radius/height/color (Add Data Validation)
		do {
			cout << "Enter radius (between 10 and 285): ";
			cin >> radius;
			cin.ignore();
		} while (radius < 10 || radius > 285);

		do {
			cout << "Enter height (between 10 and 300): ";
			cin >> height;
			cin.ignore();
		} while (height < 10 || height > 300);
		
		do {
			cout << "Enter color of container: ";
			cin >> r >> g >> b;
			cin.ignore();
		} while ((r < 0 || r > 255) || 
				 (g < 0 || g > 255) ||
				 (b < 0 || b > 255));

		//Set the Containers radius/height /color
		container.setRadius(radius); 
		container.setHeight(height); 
		container.setColor(Color(r, g, b));

		GenPoint p = GenPoint(56, 400 - height); 
#else
		container.setRadius(100); 
		container.setHeight(200); 
		container.setColor(Color(120, 120, 120));
		//Compute the Container upper left coordinate based on the height
		GenPoint p = GenPoint(56, 400 - 200); 
#endif


		//Set the Container’s position
		container.setPosition(p);

		//Set the Container for the Simulation
		simulation.setContainer(container);

		//Draw the simulation/container (invoke draw on Simulation)
		simulation.draw();
		simulation.start();

		//Repeat the simulation?
		cout << "Repeat the simulation (y/n)? ";
		cin >> repeat;

		clearGraphics();
		system("cls");

	} while (repeat == 'y' || repeat == 'Y');

	return 0;
}
