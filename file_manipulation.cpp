#include "file_manipulation.h"
#include "employee_class.h"
#include "dynamic_array.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

bool checkFileStream(string filename, bool isFail) {
  if (isFail) {
    cout << "File: " << filename << " cannot be opened. Terminating the program..." << endl;
  } else {
    cout << "File: " << filename << " has been successfully opened, its contents are being loaded..." << endl;
  }

  return !(isFail);
}

bool openIfstream(ifstream & fin, string filename) {
  fin.open(filename.c_str());
  return checkFileStream(filename, fin.fail());
}

bool openOfstream(ofstream & fout, string filename) {
  fout.open(filename.c_str());
  return checkFileStream(filename, fout.fail());
}

// read employee data file and return array of employee classes
Employee * readEmployeeDataFile(ifstream &fin, int & employeeCounter) {
  // create dynamic array with initial size of 5
  int employeesArraySize = 5;
  Employee * employeesArray = new Employee[employeesArraySize];
  Employee thisEmployee;

  // read the first line as a header
  string headerLine;
  getline(fin, headerLine);

  // create employee according to each line of data read
  string dataLine;
  employeeCounter = 0;
  int dataLineDelimiterPosition;
  int numberOfEmployeeAttributes = thisEmployee.getNumberOfEmployeeAttributes();
  string * employeeAttributes = new string[numberOfEmployeeAttributes];
  int employeeAttributesCounter;

  // read each line of data
  while (getline(fin, dataLine)) {
    // read each employee attribute into array
    employeeAttributesCounter = 0;
    while ((dataLineDelimiterPosition = dataLine.find(" |")) != string::npos) {
      employeeAttributes[employeeAttributesCounter++] = dataLine.substr(0, dataLineDelimiterPosition);
      dataLine.erase(0, dataLineDelimiterPosition + 3);
    }

    // store this employee's attributes by calling setter function
    thisEmployee.setAllAttributes(employeeAttributes);
    // store this employee's data read from current dataLine into array
    // expand array if array size is too small
    if (employeeCounter + 1 == employeesArraySize) {
      expandEmployeesArray(employeesArray, employeesArraySize);
    }
    employeesArray[employeeCounter++] = thisEmployee;
  }

  cout << "Employee data file has been read, array of employees has been created.\nNumber of employee records: " << employeeCounter << endl;

  return employeesArray;
}

void writeEmployeeDataFile(ofstream & fout, Employee * employeesArray, int employeeCounter) {
  // output header line
  fout << "First Name | Last Name | Employee ID | Age | Role | Salary | Address | Phone Number | Date of Birth | Employee Status | " << endl;

  // output each Employee in employeesArray
  Employee thisEmployee; string delimiter = " | ";
  for (int i = 0; i < employeeCounter; i++) {
    thisEmployee = employeesArray[i];
    fout << thisEmployee.getFirstName() << delimiter;
    fout << thisEmployee.getLastName() << delimiter;
    fout << thisEmployee.getEmployeeId() << delimiter;
    fout << thisEmployee.getAge() << delimiter;
    fout << thisEmployee.getRole() << delimiter;
    fout << fixed << setprecision(0) << thisEmployee.getSalary() << delimiter;
    fout << thisEmployee.getAddress() << delimiter;
    fout << thisEmployee.getPhoneNumber() << delimiter;
    fout << thisEmployee.getDateOfBirth() << delimiter;
    fout << (thisEmployee.getIsAnEmployee() ? "True" : "False") << delimiter;
    fout << endl;
  }
}
