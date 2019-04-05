#include "employee_class.h"
#include <iostream>
#include <string>

using namespace std;

Employee::Employee(void) {
  cout << "Creating a new employee..." << endl;
}

// setter functions
void Employee::setFirstName(string input) {
  firstName = input;
}

void Employee::setLastName(string input) {
  lastName = input;
}

void Employee::setEmployeeId(string input) {
  employeeId = input;
}


// getter functions
string Employee::getFirstName() {
  return firstName;
}

string Employee::getLastName() {
  return lastName;
}

string Employee::getEmployeeId() {
  return employeeId;
}
