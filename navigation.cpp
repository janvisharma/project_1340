#include "navigation.h"
#include "employee_class.h"
#include "array_manipulation.h"
#include "file_manipulation.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cctype>

using namespace std;

bool checkAndConvertToInteger(int & attributeInteger, string attributeSubstring, int numberOfEmployeeAttributes) {
  // check if substring is a number
  for (int i = 0; i < attributeSubstring.length(); i++) {
    if ((int) attributeSubstring[i] < 48 || (int) attributeSubstring[i] > 57) {
      return false;
    }
  }

  attributeInteger = stoi(attributeSubstring);
  return 0 <= attributeInteger && attributeInteger < numberOfEmployeeAttributes;
}

// User choice = 0, exit program
void exitProgram(string filename, vector <Employee> employeesArray) {
  ofstream fout;
  openOfstream(fout, filename.c_str());
  writeEmployeeDataFile(fout, employeesArray);

  cout << "*****************************************************" << endl;
  cout << "\nNord Etoile, thanks for using our employee management system. The changes made to your employee records have been fully reflected in the employee data file you loaded.\n\nWe wish you a pleasant day.\n" << endl;
  cout << "*****************************************************" << endl;
  exit(1);
}

// User choice = 4, sort employee records
void sortEmployeesArray(vector <Employee> & employeesArray) {
  // create placeholder employee to get attributesHeader data
  Employee thisEmployee;
  string * attributesHeader = thisEmployee.getAttributesHeader();

  cout << "*****************************************************" << endl;

  // prompt for sorting criteria

  // list all available attributes
  cout << "List of available employee attributes" << endl;
  for (int i = 0; i < thisEmployee.getNumberOfEmployeeAttributes(); i++) {
    cout << i << ": " << attributesHeader[i] << endl;
  }

  // prompt for selection of attributes
  string orderLine;
  cout << "\nPlease select attributes to sort accordingly. More than 1 attribute can be selected. Simply order by decreasing importance, separated by a space. Order: ";
  getline(cin, orderLine);
  while(orderLine.length() == 0) {
    getline(cin, orderLine);
  }
  // split orderLine data into vector of integers, also check if all integers are within numberOfEmployeeAttributes boundary
  vector <int> order;
  bool isValid = false;
  while (!isValid) {
    orderLine += " ";
    while(orderLine.length() != 0) {
      // get substring by removinng spaces
      string attributeSubstring = "";
      for (int i = 0; i < orderLine.length(); i++) {
        if (!isspace(orderLine[i])) {
          attributeSubstring += orderLine[i];
        } else {
          break;
        }
      }

      // check if substring is a number that is less than numberOfEmployeeAttributes
      int attributeInteger;
      isValid = checkAndConvertToInteger(attributeInteger, attributeSubstring, thisEmployee.getNumberOfEmployeeAttributes());

      if (!isValid) {
        vector<int>().swap(order);
        break;
      }

      // put into order vector
      order.push_back(attributeInteger);

      // erase substring and subsequent spaces in orderLine
      orderLine.erase(0, attributeSubstring.length());
      while (orderLine.length() != 0 && isspace(orderLine[0])) {
        orderLine.erase(0, 1);
      }
    }

    // break isValid while loop if orderLine was exhausted properly and order size is less than numberOfEmployeeAttributes
    if (isValid && order.size() < thisEmployee.getNumberOfEmployeeAttributes()) {
      break;
    }
    cout << "Invalid attributes order. Please input again: ";
    getline(cin, orderLine);
  }

  // sort according to order
  for (int i = 0; i < order.size(); i++) {
    cout << order[i] << " ";
    switch (order[i]) {
      case 0: sort(employeesArray.begin(), employeesArray.end(), compareEmployeesByFirstName);
    }
  }

  cout << "Sorting completed." << endl;
  cout << "*****************************************************" << endl;
}
