#include<iostream>
#include <iomanip>
#include <vector>
#include <cmath>

#include "graph1.h"
#include "GenPoint.h"
using namespace std;



// Function prototypes
double computeDistance(vector<GenPoint> allPoints);



int main()
{
  //Variable Declaration/Initialization
  int mx = 0;
  int my = 0;
  int obj_no = 0;
  double distance = 0;
  GenPoint p;
	vector<GenPoint> allPoints;  // Stores total rainfall for each month

  //Display Graphics Windowo
  displayGraphics();

	// Collect the points
	while(true)
	{
    //Check for mouse drag
    if (mouseDragged(mx,my))
    { 
      //Draw point
      obj_no = drawPoint(mx,my);
      setColor(obj_no,0,0,255);
    

		  cout << "Point Collected: (" << mx << ", " << my << ")" << endl;

      //Set the point
      p.setPoint(mx,my);
      allPoints.push_back(p);
		}

    //Check for up arrow to quit
    if (up())
      break;
  }
    
	
  //Compute the distance for the points
  distance = computeDistance(allPoints);

  //Random shuffle the points
  

  //Display results 
  cout << "Distance in pixels is: " << distance << endl;
  return 0;
}

double computeDistance(vector<GenPoint> vec)
{
  //Variable Declaration/Initialization
  int i = 0;
	double distance = 0.0;
  int px = 0;
  int py = 0;
  int cx = 0;
  int cy = 0;
  GenPoint p;

	for (i = 0; i < (int)vec.size(); i++)
  {
    //Retrieve the point
    p = vec[i];

    //Set the current x
    cx = p.getX();
    cy = p.getY();
    
    if (i)
    {
      distance += sqrt(pow(cx-px,2.0) + pow(cy-py,2.0));
    }

    //Reset previous
    px = cx;
    py = cy;
  }
		

	return distance;
}

