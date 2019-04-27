#include "file_manipulation.h"
#include "employee_class.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

bool checkFileStream(string filename, bool isFail) {
  if (isFail) {
    cout << "File: " << filename << " cannot be opened." << endl;
  } else {
    cout << "File: " << filename << " has been successfully opened." << endl;
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

// read employee data file and return vector array of employee classes
vector <Employee> readEmployeeDataFile(ifstream &fin) {
  // create vector array of employees
  vector <Employee> employeesArray;
  Employee thisEmployee;

  // read the first line as a header
  string headerLine;
  getline(fin, headerLine);

  // create employee according to each line of data read
  string dataLine;
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
    // store this employee's data read from current dataLine into vector
    employeesArray.push_back(thisEmployee);
  }

  cout << "Employee data file has been read, array of employees has been created.\nNumber of employee records: " << employeesArray.size() << endl;

  return employeesArray;
}

void writeEmployeeDataFile(ofstream & fout, vector <Employee> employeesArray) {
  // delimiter symbol
  string delimiter = " | ";

  // output header line
  Employee thisEmployee;
  string * attributesHeader = thisEmployee.getAttributesHeader();
  for (int i = 0; i < thisEmployee.getNumberOfEmployeeAttributes(); i++) {
    fout << attributesHeader[i] << delimiter;
  }
  fout << endl;

  // output each Employee in employeesArray
  for (int i = 0; i < employeesArray.size(); i++) {
    thisEmployee = employeesArray[i];
    fout << thisEmployee.getFirstName() << delimiter;
    fout << thisEmployee.getLastName() << delimiter;
    fout << thisEmployee.getEmployeeId() << delimiter;
    fout << thisEmployee.getAge() << delimiter;
    fout << thisEmployee.getRole() << delimiter;
    fout << fixed << setprecision(2) << thisEmployee.getSalary() << delimiter;
    fout << thisEmployee.getAddress() << delimiter;
    fout << thisEmployee.getPhoneNumber() << delimiter;
    fout << thisEmployee.getDateOfBirth() << delimiter;
    fout << (thisEmployee.getIsAnEmployee() ? "True" : "False") << delimiter;
    fout << endl;
  }
}
