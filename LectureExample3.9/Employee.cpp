#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

//Static data field initialization
int Employee::count = 0;
const double Employee::pi = 3.14159268;

//Create employee object
Employee::Employee(int salary)
{
  //Set salary
  this->salary = salary;
  id = count++;
	
}

Employee::~Employee()
{
  //Decrement counter
  count--;
  cout << "Decrementing Employee count: " << endl;
}

int Employee::getId()
{
 return id; 
}

int Employee::getSalary()
{
  return salary;
  int count = getCount();
}

int Employee::getCount()
{
  //this->id = 9;
  //Cannot access private data fields
  //return (id) - this won't work
  return count;
}

