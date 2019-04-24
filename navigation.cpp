#include "navigation.h"
#include "employee_class.h"
#include "array_manipulation.h"
#include "file_manipulation.h"
#include "handle_user_input.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cctype>

using namespace std;


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

void createNewEmployee(vector <Employee> & employeesArray)
{
  cout << "*****************************************************" << endl;

  Employee newEmployee;
  cout << "Creating a new employee. You will be prompted " << newEmployee.getNumberOfEmployeeAttributes() << " attributes." << endl;

  string attributes[10];
  vector <string> attributesPrompt = {"First Name", "Last Name", "Employee ID", "Age", "Role", "Salary", "Address", "Phone Number", "Date of Birth (Do Month YYYY)", "Employee Status (True / False)"};

  string userPrompt;

  // first prompt
  for (int i = 0; i < attributesPrompt.size(); i++) {
    userPrompt = to_string(i) + ". Enter " + attributesPrompt[i] + ": ";
    attributes[i] = handleUserInputLine(userPrompt);
  }

  // prompt for any change before putting into employees array
  bool userConfirmation = false;
  int attributeInteger;
  while (!userConfirmation) {
    cout << "Any information to be changed before creating employee record? Select between 0 to 9 as previously asked.\nEnter -1 to confirm employee record entered, -2 to cancel creation, and go back to main program." << endl;
    cout << "Enter: ";
    cin >> attributeInteger;
    if (attributeInteger == -1) {
      userConfirmation = true;
      break;
    }
    if (attributeInteger == -2) {
      return;
    }
    userPrompt = to_string(attributeInteger) + ". Enter " + attributesPrompt[attributeInteger] + ": ";
    attributes[attributeInteger] = handleUserInputLine(userPrompt);
    cout << "Attribute changed." << endl;
  }

  // set all attributes and put into employees array
  newEmployee.setAllAttributes(attributes);
  employeesArray.push_back(newEmployee);

  cout << "New employee with first name: " << newEmployee.getFirstName() << " has been created." << endl;

  cout << "*****************************************************" << endl;
}

// User choice = 2, search employee records
void searchEmployees(vector <Employee> employeesArray) {
  cout  <<  "*****************************************************" << endl ;

  // list all available attributes
  cout << "List of available employee attributes for searching:" << endl;
  cout << "List of available employee attributes for sorting:" << endl;
  cout << "1: First Name" << endl;
  cout << "2: Last Name" << endl;
  cout << "3: Employee ID" << endl;
  cout << "4: Age" << endl;
  cout << "5: Role" << endl;
  cout << "6: Salary" << endl;
  cout << "7: Phone Number" << endl;
  cout << "8: Date of Birth" << endl;
  cout << "9: Employee Status" << endl;

  int numberOfEmployeeAttributes = 9;

  // prompt for selection of 1 attribute
  string userPrompt = "Please select 1 attribute as search criteria: ";
  string attributeString = getValueFromStringStream(userPrompt);
  int attributeInteger;
  while (!checkAndConvertToIntegerForEmployeeAttributes(attributeInteger, attributeString, numberOfEmployeeAttributes)) {
    userPrompt = "Invalid attribute selected. Please input again: ";
    attributeString = getValueFromStringStream(userPrompt);
  }

  // search by using switch, prompt for searchValue
  vector <Employee> filteredEmployeesArray;
  switch (attributeInteger) {
    case 1: {
      string searchValue = getValueByLongString("first name");
      filterEmployeesByFirstName(employeesArray, filteredEmployeesArray, searchValue);
      break;
    }
    case 2: {
      string searchValue = getValueByLongString("last name");
      filterEmployeesByLastName(employeesArray, filteredEmployeesArray, searchValue);
      break;
    }
    case 3: {
      string searchValue = getValueByString("employee id");
      filterEmployeesByEmployeeId(employeesArray, filteredEmployeesArray, searchValue);
      break;
    }
    case 4: {
      int searchValue = getValueByInteger("age");
      filterEmployeesByAge(employeesArray, filteredEmployeesArray, searchValue);
      break;
    }
    case 5: {
      string searchValue = getValueByLongString("role");
      filterEmployeesByRole(employeesArray, filteredEmployeesArray, searchValue);
      break;
    }
    case 6: {
      double searchValue = getValueByDouble("salary");
      filterEmployeesBySalary(employeesArray, filteredEmployeesArray, searchValue);
      break;
    }
    case 7: {
      string searchValue = getValueByString("phone number");
      filterEmployeesByPhoneNumber(employeesArray, filteredEmployeesArray, searchValue);
      break;
    }
    case 8: {
      string searchValue = getValueByLongString("date of birth (Do Month YYYY)");
      filterEmployeesByDateOfBirth(employeesArray, filteredEmployeesArray, searchValue);
      break;
    }
    case 9: {
      bool searchValue = getValueByBoolean("employee status (true / false)");
      filterEmployeesByIsAnEmployee(employeesArray, filteredEmployeesArray, searchValue);
      break;
    }

    // default case not required (user input handled properly)
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
  cout << "List of available employee attributes for sorting:" << endl;
  cout << "1: First Name" << endl;
  cout << "2: Last Name" << endl;
  cout << "3: Employee ID" << endl;
  cout << "4: Age" << endl;
  cout << "5: Role" << endl;
  cout << "6: Salary" << endl;
  cout << "7: Phone Number" << endl;
  cout << "8: Employee Status" << endl;

  int numberOfEmployeeAttributes = 8;

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
  for (int i = order.size() - 1; i >= 0; i--) {
    // handle each attribute using a switch
    switch (order[i]) {
      case 1: {
        sort(employeesArray.begin(), employeesArray.end(), compareEmployeesByFirstName);
        break;
      }
      case 2: {
        sort(employeesArray.begin(), employeesArray.end(), compareEmployeesByLastName);
        break;
      }
      case 3: {
        sort(employeesArray.begin(), employeesArray.end(), compareEmployeesByEmployeeId);
        break;
      }
      case 4: {
        sort(employeesArray.begin(), employeesArray.end(), compareEmployeesByAge);
        break;
      }
      case 5: {
        sort(employeesArray.begin(), employeesArray.end(), compareEmployeesByRole);
        break;
      }
      case 6: {
        sort(employeesArray.begin(), employeesArray.end(), compareEmployeesBySalary);
        break;
      }
      case 7: {
        sort(employeesArray.begin(), employeesArray.end(), compareEmployeesByPhoneNumber);
        break;
      }
      case 8: {
        sort(employeesArray.begin(), employeesArray.end(), compareEmployeesByIsAnEmployee);
        break;
      }

      // default case not required (user input handled properly)
    }
  }

  cout << "Sorting completed.\n" << endl;
  cout << "*****************************************************" << endl;
}
