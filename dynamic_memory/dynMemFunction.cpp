#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;

int* setTargetsX( int no_targets);
int* setTargetsY( int no_targets);
int* displayTargets(int* x, int* y, int no_targets);
void blinkTargets(int* targets, int* x, int* y, int no_targets);

int main()
{
  //Variable Declaration/Intiialization
  int* x = NULL;
  int* y = NULL;
  int* targets = NULL;
  int no_targets = 0;

  //Display Graphics
  displayGraphics();

  //Prompt user for the number of targets
  cout << "Enter # targets to display: ";
  cin >> no_targets;

 //Initialize random # generator
  srand(time(0));

  //Set x-coord
  x = setTargetsX(no_targets);
  
  //Set y-coord
  y = setTargetsY(no_targets);

  //Display targets
  targets = displayTargets(x,y,no_targets);

  //Make the targets blink (red-green/green-red)
  blinkTargets(targets,x,y,no_targets);

  //Cleanup memory
  delete[] x;
  delete[] y;
  delete[] targets;

  return 0;
  
   
}

int* setTargetsX( int no_targets)
{
  //Variable Declaration/Intitialization
  int i = 0;
  int* x = NULL;

  //Dynamically allocate the arrays
  x = new int[no_targets];

  //Set the x coord for the targets
  for (i = 0; i < no_targets; i++)  
  {
    //Set x/y coordinates
    x[i] = (rand()%600);
  }


  return(x);
}

int* setTargetsY( int no_targets)
{
  //Variable Declaration/Intitialization
  int i = 0;
  int* y = NULL;

  //Dynamically allocate the array
  y = new int[no_targets];

  //Set the x coord for the targets
  for (i = 0; i < no_targets; i++)  
  {
    //Set x/y coordinates
    y[i] = (rand()%440);
  }


  return(y);
}

int* displayTargets(int* x, int* y, int no_targets)
{
  //Variable Declaration/Initialization
  int i = 0;
  int* targets = NULL;

  //Dynamically allocate targets
  targets = new int[no_targets];

  for (i = 0; i < no_targets; i++)
  {
    //Set the image
    if ((i%2) == 0)
      targets[i] = displayBMP("target1.bmp",x[i],y[i]);
    else
      targets[i] = displayBMP("target2.bmp",x[i],y[i]);
  }

  return(targets);
}

void blinkTargets(int* targets, int* x, int* y, int no_targets)
{
  //Variable Declaration/Initialization
  int i = 0;
  int j = 0;

  for (i = 0; i < 50; i++)
  {
    for (j = 0 ; j < no_targets; j++)
    {
      if ( (i%2 == 0) && (j%2== 0) )
      {
        //Remove current target
        removeObject(targets[j]);
      
        //Replace with new target
        targets[j] = displayBMP("target2.bmp",x[j],y[j]);
      }
      else if ( (i%2 == 0) && (j%2== 1) )
      {
        //Remove current target
        removeObject(targets[j]);
      
        //Replace with new target
        targets[j] = displayBMP("target1.bmp",x[j],y[j]);
      }       
     else if ( (i%2 == 1) && (j%2== 0) )
      {
        //Remove current target
        removeObject(targets[j]);
      
        //Replace with new target
        targets[j] = displayBMP("target1.bmp",x[j],y[j]);
      }
      else if ( (i%2 == 1) && (j%2== 1) )
      {
        //Remove current target
        removeObject(targets[j]);
      
        //Replace with new target
        targets[j] = displayBMP("target2.bmp",x[j],y[j]);
      }       
    }
  }

}