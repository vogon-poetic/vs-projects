#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
  private:
    int id;
    int salary;
    static int count;
    const static double pi;
    
  public:
    Employee(int salary);
    ~Employee();
    int getId();
    int getSalary();
    static int getCount();
};

#endif

