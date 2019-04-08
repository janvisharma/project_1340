#include "file_manipulation.h"
#include "employee_class.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool checkFileStream(string filename, bool isFail) {
  if (isFail) {
    cout << "File: " << filename << " cannot be opened. Terminating the program..." << endl;
  } else {
    cout << "File: " << filename << " has been successfully opened, its contents are being loaded..." << endl;
  }

  return !(isFail);
}

ifstream openIfstream(string filename) {
  ifstream fin (filename.c_str());
  return fin;
}

// read employee data file and return array of employee classes
Employee * readEmployeeDataFile(ifstream& fin) {
  // create dynamic array
  int employeesArraySize = 5;
  Employee * employeesArray = new Employee[employeesArraySize];
  Employee thisEmployee;

  // read the first line as a header
  string headerLine;
  getline(fin, headerLine);

  // create employee according to each line of data read
  string dataLine;
  int employeeCounter = 0;
  int dataLineDelimiterPosition;
  int numberOfEmployeeAttributes = thisEmployee.getNumberOfEmployeeAttributes();
  string * employeeAttributes = new string[numberOfEmployeeAttributes];
  int employeeAttributesCounter;

  while (getline(fin, dataLine)) {
    // read each data attribute
    employeeAttributesCounter = 0;
    while ((dataLineDelimiterPosition = dataLine.find(" |")) != string::npos) {
      employeeAttributes[employeeAttributesCounter++] = dataLine.substr(0, dataLineDelimiterPosition);
      dataLine.erase(0, dataLineDelimiterPosition + 3);
    }

    // store this employee's attributes by calling setter function
    // thisEmployee.setAllAttributes(employeeAttributes);
    thisEmployee.setFirstName(employeeAttributes[0]); // for testing only
    thisEmployee.setLastName(employeeAttributes[1]); // for testing only
    // store this employee's data read from current dataLine into array
    employeesArray[employeeCounter++] = thisEmployee;
  }

  cout << "Employee data file has been read, array of employees has been created..." << endl;
  return employeesArray;
}
