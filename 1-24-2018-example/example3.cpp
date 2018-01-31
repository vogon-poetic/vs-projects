#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;

void getNoCircles(int* no_circles_ptr);
void setData(int* x, int* y, int no_circles);
void displayCircles(int* objects, int* x, int* y, int no_circles);
void blinkCircles(int* object, int no_circles);



int main()
{
  //Variable Declaration/Initialization
  int i = 0;
  int no_circles = 0;
  const int MAX_CIRCLES = 50;
  int x[MAX_CIRCLES] = {0};
  int y[MAX_CIRCLES] = {0};
  int objects[MAX_CIRCLES] = {0};
  int array[3] = {0,1,2};
  int* aptr = NULL;

  //Display graphics
  displayGraphics();

  //Graphic example using pointers
  getNoCircles(&no_circles);

  //Get data for circles
  setData(x,y,no_circles);

  //Display circles
  displayCircles(objects,x,y,no_circles);

  //Move the circles
  blinkCircles(objects,no_circles);


  return 0;
  
}

void getNoCircles(int* no_circles_ptr)
{
  //Prompt for the # of circles (must be > 0 and < 10)
  do
  {
    cout << "Enter # of circles (> 0 but < 10): ";
    cin >> *no_circles_ptr;

  }while( (*no_circles_ptr < 0) || (*no_circles_ptr > 10) );
}

void setData(int* x, int* y, int no_circles)
{
  //Variable Declaration/Initialization
  int i = 0;

  //Initialize random gen seed
  srand(time(0));

  //Generate random x/y values
  for (i = 0; i < no_circles; i++)
  {
    x[i] = rand()%640;  
    y[i] = rand()%480;
  }
}

void displayCircles(int* objects, int* x, int* y, int no_circles)
{
  //Variable Declaration/initialization
  int i = 0;

  //Display each circle
  for (i = 0; i < no_circles; i++)
  {
    objects[i] = drawCircle(10,x[i],y[i]);
  }
}

void blinkCircles(int* object, int no_circles)
{
  //Variable Declarations/initializations
  int i = 0;
  int j = 0;

  //Have circles blink for 10 times
  for (j = 0; j < 10; j++)
  {
    for (i = 0; i < no_circles; i++)
    {
      setColor(object[i],255,0,0);
    
      Sleep(100);
      setColor(object[i],255,255,255);
     
    }
  }
}
