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
void readEmployeeDataFile(ifstream fin) {
  // create dynamic array
  // Employee * employeesArray = new Employee [5];

  // read the first line as a header
  string headerLine;
  getline(fin, headerLine);

  // create employee according to each line of data read
  string dataLine;
  int employeeCounter = 0;
  int dataLineDelimiterPosition;
  // int numberOfEmployeeAttributes = getNumberOfEmployeeAttributes();
  // string employeeAttributes = new string[numberOfEmployeeAttributes];
  string employeeAttributes[9]; int employeeAttributesCounter = 0;
  while (getline(fin, dataLine)) {
    // Employee thisEmployee;
    // read each data attribute
    while ((dataLineDelimiterPosition = dataLine.find(" | ")) != string::npos) {
      employeeAttributes[employeeAttributesCounter++] = dataLine.substr(0, dataLineDelimiterPosition);
      cout << employeeAttributes[employeeAttributesCounter - 1] << endl; // temporary
      dataLine.erase(0, dataLineDelimiterPosition + 3);
    }

  }
}
