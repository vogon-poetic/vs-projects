#include <iostream>

using namespace std;

//Class Declaration
class Employee
{
  private:           //These are the private data fields
    int id;
    int dept_id;
    int yrs_svc;

  public:
    Employee(); // Line 17, 18 are *constructors*
    Employee(int id_val, int dept_id_val, int yrs_svc);
    void setId(int id); 
    void setDeptId(int dept_id);
    int getId();
    void setYrsSvc(int yrs_svc);
    int getYrsSvc();
    bool detSvcAward();

};

Employee::Employee(int id_val, int dept_id_val, int yrs_svc_val )
{
    setId(id_val); 
    setDeptId(dept_id_val); 
    setYrsSvc(yrs_svc_val);
}

Employee::Employee()
{
    id = 0;
    dept_id = 0;
    yrs_svc = 0;
    
}

//Class Implementation
void Employee::setId(int id_val)
{
    id = id_val;
}

void Employee::setDeptId(int dept_id_val)
{
 dept_id = dept_id_val;
}

void Employee::setYrsSvc(int yrs_svc_val)
{
    yrs_svc = yrs_svc_val;
}

int Employee::getYrsSvc()
{
    //Date date = hire_date - curr_date;
    //Convert date to int no_yrs
    //int no_yrs
    return(yrs_svc);
}



//Implement all other setters
//Implement a getter for id

int Employee::getId()
{
    return(id);
}

bool Employee::detSvcAward()
{
    if (yrs_svc > 5)
       return(true);
    else
       return(false);
}


int main()
    
{
    //Variable Declaration/Initialization
    Employee emp1;
    Employee emp2(1807,21,3);
    int id = 0;
    int id1 = 0;

    //Set the id for emp1
    emp1.setId(1806);
 
    //Retrieve the id for emp1/emp2
    id = emp1.getId();
    id1 = emp2.getId();

    return 0;

}

