#include <iostream>
#include "graph1.h"
#include "Circle.h"
#include "ColorCircle.h"
#include "ColorFilledCircle.h"

using namespace std;

int main()
{
  //Variable Declaration/Initialization
  int x = 0;
  int y = 0;
  int r = 0;
  int g = 0;
  int b = 0;
  int radius = 0;
  Circle circle1;
  Circle circle2(200,200,30);
  ColorCircle circle3;
  ColorFilledCircle circle4;

  //Display the Graphics Window
  displayGraphics();

  /*****************************************************************************************/
  //Draw the default circle
  circle1.draw();

  //Print info about default circle
  circle1.print();

  //Repeat for parameterized circle
  //Draw the parameterized circle
  circle2.draw();

  //Print info about parameterized circle
  circle2.print();
  /****************************************************************************************/

  //Prompt for coordinates for ColorCircle
  cout << "Enter x/y coordinate: ";
  cin >> x >> y;
  
  //Prompt for radius
  cout << "Enter radius: ";
  cin >> radius;

  //Prompt for Color
  cout << "Enter color: ";
  cin >> r >> g >> b;

  //Set the circle
  circle3.setX(x);
  circle3.setY(y);
  circle3.setRadius(radius);
  
  //Set the color
  circle3.setR(r);
  circle3.setG(g);
  circle3.setB(b);

  //Draw/Print the ColorCircle
  circle3.draw();
  circle3.print();


  /***********************************************************************/
    //Prompt for coordinates for ColorFilledCircle
  cout << "Enter x/y coordinate: ";
  cin >> x >> y;
  
  //Prompt for radius
  cout << "Enter radius: ";
  cin >> radius;

  //Prompt for Color
  cout << "Enter color: ";
  cin >> r >> g >> b;

  //Set the circle
  circle4.setX(x);
  circle4.setY(y);
  circle4.setRadius(radius);
  
  //Set the color
  circle4.setR(r);
  circle4.setG(g);
  circle4.setB(b);

  //Draw/Print the ColorCircle
  circle4.draw();
  circle4.print();

  return 0;
}