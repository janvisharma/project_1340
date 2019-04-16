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
    void setAge(string);
    void setRole(string);
    void setSalary(string);
    void setAddress(string);
    void setPhoneNumber(string);
    void setDateOfBirth(string);
    void setIsAnEmployee(string);

    void setAllAttributes(string []);

    // getter functions
    string getFirstName(void);
    string getLastName(void);
    string getEmployeeId(void);
    int getAge(void);
    string getRole(void);
    double getSalary(void);
    string getAddress(void);
    string getPhoneNumber(void);
    string getDateOfBirth(void);
    bool getIsAnEmployee(void);
  
    int getNumberOfEmployeeAttributes(void);

  private:
    string firstName;
    string lastName;
    string employeeId;
    int age;
    string role;
    double salary;
    string address;
    string phoneNumber;
    string dateOfBirth;
    bool isAnEmployee;
    int numberOfEmployeeAttributes = 10;
};

#endif
