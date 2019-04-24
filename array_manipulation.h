#include <string>
#include <vector>
#include "employee_class.h"

using namespace std;

// filter functions for sorting
void filterEmployeesByFirstName(vector <Employee>, vector <Employee> &, string);

void filterEmployeesByLastName(vector <Employee>, vector <Employee> &, string);

void filterEmployeesByEmployeeId(vector <Employee>, vector <Employee> &, string);

void filterEmployeesByAge(vector <Employee>, vector <Employee> &, int);

void filterEmployeesByRole(vector <Employee>, vector <Employee> &, string);

void filterEmployeesBySalary(vector <Employee>, vector <Employee> &, double);

void filterEmployeesByPhoneNumber(vector <Employee>, vector <Employee> &, string);

void filterEmployeesByDateOfBirth(vector <Employee>, vector <Employee> &, string);

void filterEmployeesByIsAnEmployee(vector <Employee>, vector <Employee> &, bool);

// comparision functions for searching
bool compareEmployeesByFirstName(Employee, Employee);

bool compareEmployeesByLastName(Employee, Employee);

bool compareEmployeesByEmployeeId(Employee, Employee);

bool compareEmployeesByAge(Employee, Employee);

bool compareEmployeesByRole(Employee, Employee);

bool compareEmployeesBySalary(Employee, Employee);

bool compareEmployeesByPhoneNumber(Employee, Employee);

bool compareEmployeesByIsAnEmployee(Employee, Employee);
