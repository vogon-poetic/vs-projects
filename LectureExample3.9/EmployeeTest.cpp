#include <iostream>
#include "Employee.h"

using namespace std;

int main()
{
  //Can access public static methods without instantiating an object
  cout << "Current Employee Count" << Employee::getCount() << endl;
  
  //What occurs here?
  Employee *employee1 = new Employee(23000);
  Employee *employee2 = new Employee(33000);
  
  //What is displayed here?
  cout << Employee::getCount() << endl;
  
  //What occurs here?
  delete employee1;
  
  //What is displayed here?
  cout << Employee::getCount() << endl;
  
  return 0;
}