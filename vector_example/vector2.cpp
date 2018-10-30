#include<iostream>
#include <vector>
#include "GenPoint.h"
#include "graph1.h"

using namespace std;

class Shape
{
  protected:
    string name;

  public:
    Shape() {name = "";}
    Shape(string name)
    {
      this->name = name;
 
    }
    
    //Getter
    string getName()
    {
      return(name);
    }
    virtual string getInfo() = 0;
};

class Quadrilateral : public Shape
{
  public:
    Quadrilateral() { }
    Quadrilateral(string name) : Shape(name) {};
    string getInfo()
    {
      return "In Quadrilateral " + name;
    }
};

class GenRectangle : public Quadrilateral
{
  public:
    GenRectangle() { }
    GenRectangle(string name) : Quadrilateral(name) {};

    string getInfo()
    {
      return "In GenRectangle " + name;
    }

};


class Square : public GenRectangle
{
 public:
    Square() { }
    Square(string name) : GenRectangle(name) {};

    string getInfo()
    {
      return "In Square " + name;
    }
};

int main()
{
  //Variable Declaration/Initaization
  int i = 0;
  int count = 0;
  Shape* shape;
  vector<Shape*> allShapes; 

  //Add a shape
  allShapes.push_back(new Quadrilateral("Quadrilateral"));
  allShapes.push_back(new GenRectangle("GenRectangle"));
  allShapes.push_back(new Square("Square"));
 

  //Get the shapes back
  for (i = 0; i < (int)allShapes.size(); i++)
  {
    //Get the shape
    shape = allShapes[i];
    cout << "Name is " << shape->getName() << endl;
    cout << "Info is " << shape->getInfo() << endl;
  }

  return 0;
}
  
