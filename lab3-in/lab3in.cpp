//Lab 3 in
//Displays a set of images at random location

#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;

//Protoypes
int getNoObjects();
int* getXCoords(int no_objects);
int* getYCoords(int no_objects);
void displayObjects(int* x_coords, int* y_coords, int no_objects);

int main()
{
	//Variable Declaration/Initialization
	int no_objects = 0;
	int* x_coords = NULL;
	int* y_coords = NULL;

	//Initialize seed
	srand(time(0));

	//Display graphics
	displayGraphics();

	//1. Get the number of objects to be displayed
	no_objects = getNoObjects();

	//2. Generate the x-coords for each object
	x_coords = getXCoords(no_objects);

	//3. Generate the y-coords for each object
	y_coords = getYCoords(no_objects);

	//4. Display the objects at the randomly generated coordinates
	displayObjects(x_coords, y_coords, no_objects);

	//Cleanup memory	
	delete[] x_coords;
	delete[] y_coords;

	return 0;
}

//Implement functions below
int getNoObjects()
{
	//Variable declaration/initialization
	int num = 0;

	do {
		//Prompt for # objects – should be between 2 and 30 inclusive
		cout << "Enter # of objects: ";
		cin >> num;
		cin.ignore();
	} while (num < 2 || num > 30);

	return num;
}

int* getXCoords(int no_objects)
{
	//Variable declaration/initialization
	int* x_coords = NULL;

	//Dynamically allocate the array for x-coords
	x_coords = new int[no_objects];

	//Generates x-coords for each object randomly
	for (int i = 0; i < no_objects; ++i) {
		x_coords[i] = (rand() % 600) + 1;
	}

	return x_coords;
}

int* getYCoords(int no_objects)
{
	//Variable declaration/initialization
	int* y_coords = NULL;

	//Dynamically allocate the array for y-coords
	y_coords = new int[no_objects];

	//Generates y-coords for each object randomly
	for (int i = 0; i < no_objects; ++i) {
		y_coords[i] = (rand() % 440) + 1;
	}

	return y_coords;
}

void displayObjects(int* x_coords, int* y_coords, int no_objects)
{
	//Variable declaration/initialization
	int* objects = NULL;

	//Dynamically allocate objects to have no_objects
	objects = new int[no_objects];

	for (int i = 0; i < no_objects; i++)
	{
		//Set the image
		if ((i % 2) == 0)
			objects[i] = displayPNG("even.png", x_coords[i], y_coords[i]);
		else
			objects[i] = displayPNG("odd.png", x_coords[i], y_coords[i]);
	}
}
