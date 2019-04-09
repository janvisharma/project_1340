#include "dynamic_array.h"
#include "employee_class.h"
#include <iostream>

using namespace std;

Employee * expandEmployeesArray(Employee * &employeesArray, int &currentArraySize) {
  Employee * largerEmployeesArray = new Employee[currentArraySize + 5];
  // copy all existing data from old smaller array to new larger array
  for (int i = 0; i < currentArraySize; i++) {
    largerEmployeesArray[i] = employeesArray[i];
  }
  currentArraySize += 5;
  // free up memory space allocated to old array
  delete [] employeesArray;

  return largerEmployeesArray;
}
