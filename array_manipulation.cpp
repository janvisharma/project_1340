#include <iostream>
#include <string>
#include <vector>
#include "employee_class.h"

using namespace std;

// comparison functions
bool compareEmployeesByFirstName(Employee employeeA, Employee employeeB) {
  return employeeA.getFirstName() <= employeeB.getFirstName();
}

bool compareEmployeesByLastName(Employee employeeA, Employee employeeB) {
  return employeeA.getLastName() <= employeeB.getLastName();
}

// filter functions

// convert string to lowercase
void convertStringToLower(string & string) {
  for (int i = 0; i < string.size(); i++) {
    if (isalpha(string[i])) {
      string[i] = tolower(string[i]);
    }
  }
}

void filterEmployeesByFirstName(vector <Employee> employeesArray, vector <Employee> & filteredEmployeesArray, string searchValue) {
  for (int i = 0; i < employeesArray.size(); i++) {
    string thisEmployeeFirstName = employeesArray[i].getFirstName();
    convertStringToLower(thisEmployeeFirstName);
    if (thisEmployeeFirstName == searchValue) {
      filteredEmployeesArray.push_back(employeesArray[i]);
    }
  }
}

void filterEmployeesByLastName(vector <Employee> employeesArray, vector <Employee> & filteredEmployeesArray, string searchValue) {
  for (int i = 0; i < employeesArray.size(); i++) {
    string thisEmployeeLastName = employeesArray[i].getLastName();
    convertStringToLower(thisEmployeeLastName);
    if (thisEmployeeLastName == searchValue) {
      filteredEmployeesArray.push_back(employeesArray[i]);
    }
  }
}
