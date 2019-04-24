#include "array_manipulation.h"
#include "employee_class.h"
#include "handle_user_input.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// comparison functions
bool compareEmployeesByFirstName(Employee employeeA, Employee employeeB) {
  return employeeA.getFirstName() <= employeeB.getFirstName();
}

bool compareEmployeesByLastName(Employee employeeA, Employee employeeB) {
  return employeeA.getLastName() <= employeeB.getLastName();
}

bool compareEmployeesByEmployeeId(Employee employeeA, Employee employeeB) {
  return employeeA.getEmployeeId() <= employeeB.getEmployeeId();
}

bool compareEmployeesByAge(Employee employeeA, Employee employeeB) {
  return employeeA.getAge() <= employeesB.getAge();
}

bool compareEmployeesByRole(Employee employeeA, Employee employeeB) {
  return employeeA.getRole() <= employeeB.getRole();
}

bool compareEmployeesBySalary(Employee employeeA, Employee employeeB) {
  return employeeA.getSalary() <= employeeB.getSalary();
}

bool compareEmployeesByPhoneNumber(Employee employeeA, Employee employeeB) {
  return employeeA.getPhoneNumber() <= employeeB.getPhoneNumber();
}

bool compareEmployeesByIsAnEmployee(Employee employeeA, Employee employeeB) {
  int tempA=-1,tempB=-1;
  if(employeeA.getIsAnEmployee())
  {
    tempA = 1;
  }
  else {tempA = 0;}
  if(employeesB.getIsAnEmployee())
  {
    tempB = 1;
  }
  else {tempB = 0;}

  if(tempA>=tempB)
  {
    return true;
  }
  else {return false;}

}


// filter functions
void filterEmployeesByFirstName(vector <Employee> employeesArray, vector <Employee> & filteredEmployeesArray, string searchValue) {
  convertStringToLower(searchValue);
  for (int i = 0; i < employeesArray.size(); i++) {
    string thisEmployeeFirstName = employeesArray[i].getFirstName();
    convertStringToLower(thisEmployeeFirstName);
    if (thisEmployeeFirstName == searchValue) {
      filteredEmployeesArray.push_back(employeesArray[i]);
    }
  }
}

void filterEmployeesByLastName(vector <Employee> employeesArray, vector <Employee> & filteredEmployeesArray, string searchValue) {
  convertStringToLower(searchValue);
  for (int i = 0; i < employeesArray.size(); i++) {
    string thisEmployeeLastName = employeesArray[i].getLastName();
    convertStringToLower(thisEmployeeLastName);
    if (thisEmployeeLastName == searchValue) {
      filteredEmployeesArray.push_back(employeesArray[i]);
    }
  }
}

void filterEmployeesByEmployeeId(vector <Employee> employeesArray, vector <Employee> & filteredEmployeesArray, string searchValue) {
  for (int i = 0; i < employeesArray.size(); i++) {
    string thisEmployeeEmployeeId = employeesArray[i].getEmployeeId();
    if (thisEmployeeEmployeeId == searchValue) {
      filteredEmployeesArray.push_back(employeesArray[i]);
    }
  }
}

void filterEmployeesByAge(vector <Employee> employeesArray, vector <Employee> & filteredEmployeesArray, int searchValue) {

  for (int i = 0; i < employeesArray.size(); i++) {
    int thisEmployeeAge = employeesArray[i].getAge();
    if (thisEmployeeFirstName == searchValue) {
      filteredEmployeesArray.push_back(employeesArray[i]);
    }
  }
}

void filterEmployeesByRole(vector <Employee> employeesArray, vector <Employee> & filteredEmployeesArray, string searchValue) {
  convertStringToLower(searchValue);
  for (int i = 0; i < employeesArray.size(); i++) {
    string thisEmployeeRole = employeesArray[i].getRole();
    convertStringToLower(thisEmployeeRole);
    if (thisEmployeeRole == searchValue) {
      filteredEmployeesArray.push_back(employeesArray[i]);
    }
  }
}

void filterEmployeesBySalary(vector <Employee> employeesArray, vector <Employee> & filteredEmployeesArray, double searchValue) {

  for (int i = 0; i < employeesArray.size(); i++) {
    double thisEmployeeSalary = employeesArray[i].getSalary();

    if (thisEmployeeSalary == searchValue) {
      filteredEmployeesArray.push_back(employeesArray[i]);
    }
  }
}

void filterEmployeesByPhoneNumber(vector <Employee> employeesArray, vector <Employee> & filteredEmployeesArray, string searchValue) {
  convertStringToLower(searchValue);
  for (int i = 0; i < employeesArray.size(); i++) {
    string thisEmployeePhoneNumber = employeesArray[i].getPhoneNumber();
    convertStringToLower(thisEmployeePhoneNumber);
    if (thisEmployeePhoneNumber == searchValue) {
      filteredEmployeesArray.push_back(employeesArray[i]);
    }
  }
}

void filterEmployeesByDateOfBirth(vector <Employee> employeesArray, vector <Employee> & filteredEmployeesArray, string searchValue) {
  convertStringToLower(searchValue);
  for (int i = 0; i < employeesArray.size(); i++) {
    string thisEmployeeDateOfBirth = employeesArray[i].getDateOfBirth();
    convertStringToLower(thisEmployeeDateOfBirth);
    if (thisEmployeeDateOfBirth == searchValue) {
      filteredEmployeesArray.push_back(employeesArray[i]);
    }
  }
}

void filterEmployeesByIsAnEmployee(vector <Employee> employeesArray, vector <Employee> & filteredEmployeesArray, bool searchValue) {
  for (int i = 0; i < employeesArray.size(); i++) {
    bool thisEmployeeIsAnEmployee = employeesArray[i].getIsAnEmployee();
    if (thisEmployeeIsAnEmployee == searchValue) {
      filteredEmployeesArray.push_back(employeesArray[i]);
    }
  }
}
