#include <iostream>
#include "graph1.h"
#include "LinkedList.h"

using namespace std;

int main()
{
	//Variable Declaration/Initialization
	int i = 0;
	int x = 0;
	int y = 0;
	char repeat = 'y';
	GenPoint point;
	LinkedList list;

	//Display graphics
	displayGraphics();

	//Repeat program as many times as desired
	do
	{
		//Prompt for as many points as desired
		do
		{
			//Get x/y coordinates for a point
			cout << "Enter x/y coordinates for Point #" << (i + 1) << ": ";
			cin >> x >> y;

			//Set the GenPoint
			point.setPoint(x, y);

			//Add the point to the list
			list.addNode(point);

			//Increment the counter
			i++;

			cout << "Add another point? (y/n): ";
			cin >> repeat;

		} while ((repeat == 'y') || (repeat == 'Y'));


		//Draw the map/route
		list.draw();

	} while ((repeat == 'y') || (repeat == 'Y'));

	return 0;

}
