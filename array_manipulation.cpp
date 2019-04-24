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
