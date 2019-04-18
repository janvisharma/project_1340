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

int listEmployeeAttributes() {
  // create placeholder employee to get attributesHeader data
  Employee thisEmployee;
  string * attributesHeader = thisEmployee.getAttributesHeader();

  cout << "List of available employee attributes" << endl;
  for (int i = 0; i < thisEmployee.getNumberOfEmployeeAttributes(); i++) {
    cout << i << ": " << attributesHeader[i] << endl;
  }

  return thisEmployee.getNumberOfEmployeeAttributes();
}

string handleUserInputLine(string userPrompt) {
  string inputLine;
  cout << "\n" << userPrompt;
  getline(cin, inputLine);
  while(inputLine.length() == 0) {
    getline(cin, inputLine);
  }
  return inputLine;
}

bool checkAndConvertToInteger(int & valueInteger, string valueString) {
  if (valueString.length() == 0) {
    return false;
  }
  // check if valueString is an integer
  for (int i = 0; i < valueString.length(); i++) {
    if ((int) valueString[i] < 48 || (int) valueString[i] > 57) {
      return false;
    }
  }

  valueInteger = stoi(valueString);
  return true;
}

bool checkAndConvertToIntegerForEmployeeAttributes(int & attributeInteger, string attributeSubstring, int numberOfEmployeeAttributes) {
  bool isInteger = checkAndConvertToInteger(attributeInteger, attributeSubstring);
  return isInteger && 0 <= attributeInteger && attributeInteger < numberOfEmployeeAttributes;
}

bool checkAndConvertToDouble(double & valueDouble, string valueString) {
  if (valueString.length() == 0) {
    return false;
  }

  // check if valueString is a double
  int numberOfDots = 0;
  for (int i = 0; i < valueString[i]; i++) {
    int castedCharacter = (int) valueString[i];
    if (castedCharacter == 46) {
      numberOfDots++;
    } else if (castedCharacter < 48 || castedCharacter > 57) {
      return false;
    }
    if (numberOfDots > 1) {
      return false;
    }
  }

  valueDouble = stod(valueString);
  return true;
}

bool checkAndConvertToBoolean(bool & valueBoolean, string valueString) {
  if (valueString.length() == 0) {
    return false;
  }

  // check if valueString is a user-friendly boolean strings
  convertStringToLower(valueString);
  vector <string> truthfulBooleanStrings = {"yes", "true", "y", "t", "1"};
  vector <string> falsefulBooleanStrings = {"no", "false", "n", "f", "0"};
  if (find(truthfulBooleanStrings.begin(), truthfulBooleanStrings.end(), valueString) != truthfulBooleanStrings.end()) {
    valueBoolean = true;
    return true;
  }
  if (find(falsefulBooleanStrings.begin(), falsefulBooleanStrings.end(), valueString) != falsefulBooleanStrings.end()) {
    valueBoolean = false;
    return true;
  }

  // could not match valueString with any of the user-friendly boolean strings
  return false;
}


string getValueByString(string attribute) {
  string searchValueLine;
  string userPrompt = "Please input " + attribute + ": ";
  searchValueLine = handleUserInputLine(userPrompt);
  searchValueLine += " ";
  string searchValue = searchValueLine.substr(0, searchValueLine.find(" "));
  while (searchValue.length() == 0) {
    userPrompt = "Please input valid " + attribute + ": ";
    searchValueLine = handleUserInputLine(userPrompt);
    searchValueLine += " ";
    searchValue = searchValueLine.substr(0, searchValueLine.find(" "));
  }

  convertStringToLower(searchValue);
  return searchValue;
}

int getValueByInteger(string attribute) {
  string searchValueLine;
  int searchValue;
  string userPrompt = "Please input " + attribute + ": ";
  searchValueLine = handleUserInputLine(userPrompt);
  searchValueLine += " ";
  string searchValueString = searchValueLine.substr(0, searchValueLine.find(" "));
  while (searchValueString.length() == 0 || !checkAndConvertToInteger(searchValue, searchValueString)) {
    userPrompt = "Please input valid " + attribute + ": ";
    searchValueLine = handleUserInputLine(userPrompt);
    searchValueLine += " ";
    searchValueString = searchValueLine.substr(0, searchValueLine.find(" "));
  }
  return searchValue;
}

double getValueByDouble(string attribute) {
  string searchValueLine;
  double searchValue;
  string userPrompt = "Please input " + attribute + ": ";
  searchValueLine = handleUserInputLine(userPrompt);
  searchValueLine += " ";
  string searchValueString = searchValueLine.substr(0, searchValueLine.find(" "));
  while (searchValueString.length() == 0 || !checkAndConvertToDouble(searchValue, searchValueString)) {
    userPrompt = "Please input valid " + attribute + ": ";
    searchValueLine = handleUserInputLine(userPrompt);
    searchValueLine += " ";
    searchValueString = searchValueLine.substr(0, searchValueLine.find(" "));
  }
  return searchValue;
}

bool getValueByBoolean(string attribute) {
  string searchValueLine;
  bool searchValue;
  string userPrompt = "Please input " + attribute + ": ";
  searchValueLine = handleUserInputLine(userPrompt);
  searchValueLine += " ";
  string searchValueString = searchValueLine.substr(0, searchValueLine.find(" "));
  while (searchValueString.length() == 0 || !checkAndConvertToBoolean(searchValue, searchValueString)) {
    userPrompt = "Please input valid " + attribute + ": ";
    searchValueLine = handleUserInputLine(userPrompt);
    searchValueLine += " ";
    searchValueString = searchValueLine.substr(0, searchValueLine.find(" "));
  }
  return searchValue;
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

// User choice = 2, search employee records
void searchEmployees(vector <Employee> employeesArray) {
  cout << "*****************************************************" << endl;

  // list all available attributes
  int numberOfEmployeeAttributes = listEmployeeAttributes();

  // prompt for selection of 1 attribute
  string selectionLine;
  string userPrompt = "Please select 1 attribute as search criteria: ";
  selectionLine = handleUserInputLine(userPrompt);
  selectionLine += " ";
  string attributeString = selectionLine.substr(0, selectionLine.find(" "));
  int attributeInteger;
  while (!checkAndConvertToIntegerForEmployeeAttributes(attributeInteger, attributeString, numberOfEmployeeAttributes)) {
    userPrompt = "Invalid attribute selected. Please input again: ";
    selectionLine = handleUserInputLine(userPrompt);
    selectionLine += " ";
    attributeString = selectionLine.substr(0, selectionLine.find(" "));
  }

  // search by using switch, prompt for searchValue
  vector <Employee> filteredEmployeesArray;
  switch (attributeInteger) {
    case 0: {
      string searchValue = getValueByString("first name");
      filterEmployeesByFirstName(employeesArray, filteredEmployeesArray, searchValue);
      break;
    }
    case 1: {
      string searchValue = getValueByString("last name");
      filterEmployeesByLastName(employeesArray, filteredEmployeesArray, searchValue);
      break;
    }

    case 5: {
      double searchValue = getValueByDouble("salary");
      // filterEmployeesBySalary(employeesArray, filteredEmployeesArray, searchValue);
      break;
    }

    case 9: {
      bool searchValue = getValueByBoolean("employee status");
      // filterEmployeesByIsAnEmployee(employeesArray, filteredEmployeesArray, searchValue);
      break;
    }
  }

  // print filtered employees array
  if (filteredEmployeesArray.size() > 0) {
    cout << "Found employee" << (filteredEmployeesArray.size() > 1 ? "s" : "") << ":" << endl;
    for (int i = 0; i < filteredEmployeesArray.size(); i++) {
      cout << filteredEmployeesArray[i].getFirstName() << endl;
    }
  } else {
    cout << "No employee found..." << endl;
  }


  cout << "*****************************************************" << endl;
}

// User choice = 4, sort employee records
void sortEmployeesArray(vector <Employee> & employeesArray) {
  cout << "*****************************************************" << endl;

  // list all available attributes
  int numberOfEmployeeAttributes = listEmployeeAttributes();

  // prompt for selection of attributes
  string orderLine;
  string userPrompt = "Please select attributes to sort accordingly. More than 1 attribute can be selected. Simply order by decreasing importance, separated by a space. Order: ";
  orderLine = handleUserInputLine(userPrompt);
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
      isValid = checkAndConvertToIntegerForEmployeeAttributes(attributeInteger, attributeSubstring, numberOfEmployeeAttributes);

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
    if (isValid && order.size() < numberOfEmployeeAttributes) {
      break;
    }
    userPrompt = "Invalid attributes order. Please input again: ";
    orderLine = handleUserInputLine(userPrompt);
  }

  // sort according to order
  for (int i = 0; i < order.size(); i++) {
    // handle each attribute using a switch
    switch (order[i]) {
      case 0: {
        sort(employeesArray.begin(), employeesArray.end(), compareEmployeesByFirstName);
        break;
      }
      case 1: {
        sort(employeesArray.begin(), employeesArray.end(), compareEmployeesByLastName);
        break;
      }


    }
  }

  cout << "Sorting completed." << endl;
  cout << "*****************************************************" << endl;
}
