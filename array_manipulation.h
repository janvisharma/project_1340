#include <string>
#include <vector>
#include "employee_class.h"

// comparision functions
bool compareEmployeesByFirstName(Employee, Employee);

bool compareEmployeesByLastName(Employee, Employee);


// filter functions
void filterEmployeesByFirstName(vector <Employee>, vector <Employee> &, string);

void filterEmployeesByLastName(vector <Employee>, vector <Employee> &, string);
