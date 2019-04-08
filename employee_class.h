#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee
{
  public:
    // class constructor
    Employee();

    // setter functions
    void setFirstName(string);
    void setLastName(string);
    void setEmployeeId(string);

    // getter functions
    string getFirstName(void);
    string getLastName(void);
    string getEmployeeId(void);

    int getNumberOfEmployeeAttributes(void);

  private:
    string firstName;
    string lastName;
    string employeeId;
    int age;
    string role;
    int salary;
    string address;
    string phoneNumber;
    string dateOfBirth;
    int numberOfEmployeeAttributes = 9;
};

#endif
