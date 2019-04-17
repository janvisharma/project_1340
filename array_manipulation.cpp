#include <iostream>
#include <string>
#include <vector>
#include "employee_class.h"

using namespace std;

bool compareEmployeesByFirstName(Employee employeeA, Employee employeeB) {
  return employeeA.getFirstName() <= employeeB.getFirstName();
}
