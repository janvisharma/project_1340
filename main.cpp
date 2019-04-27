#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "employee_class.h"
#include "file_manipulation.h"
#include "navigation.h"
#include "array_manipulation.h"
#include "handle_user_input.h"

using namespace std;

int main() {
  // initial welcome and prompt for file
  cout << "-----------------------------------------------------" << endl;
  cout << "\n\tEmployee Management System" << endl;
  cout << "\nWould you like to:" << endl;
  cout << "1. Load existing employee file." << endl;
  cout << "2. Create new employee file." << endl;

  int userFileChoice = 0;
  while (userFileChoice != 1 && userFileChoice != 2) {
    userFileChoice = getValueByInteger("file choice");
  }

  string employeeDataFilename;
  string userPrompt;
  vector <Employee> employeesArray;

  // load existing file
  if (userFileChoice == 1) {
    cout << "\nWelcome back, Nord Etoile!" << endl;
    employeeDataFilename = getFileName("name of employee data file");

    ifstream fin;
    bool isOpen = openIfstream(fin, employeeDataFilename);
    while(!isOpen)
    {
      employeeDataFilename = getFileName("file name");
      isOpen = openIfstream(fin, employeeDataFilename);
    }
    employeesArray = readEmployeeDataFile(fin);
    fin.close();

  } else {
    // load new file
    cout << "\nWelcome, New User!" << endl;
    employeeDataFilename = getFileName("name of new employee data file");
  }

  cout << "-----------------------------------------------------" << endl;

  // menu-based navigation
  int userChoice;

  while (true) {
    cout << "-----------------------------------------------------" << endl;
    cout << "What do you want to do?" << endl;

    // menu
    cout << "0: Exit the program, and record changes to your employee data in the file you loaded." << endl;
    cout << "1: Create a new employee record." << endl;
    cout << "2: Search employees." << endl;
    cout << "3: Display list of employees." << endl;
    cout << "4: Sort employee records." << endl;
    cout << "5: Modify record of an employee." << endl;
    cout << "6: Fire an employee." << endl;
    cout << "7. Delete an employee record" << endl;

    cout << "-----------------------------------------------------" << endl;

    // prompt for user input
    userChoice = getValueByInteger("choice");

    switch (userChoice) {
      // all cases will call a corresponding function from navigation.h
      case 0:
        {
          exitProgram(employeeDataFilename, employeesArray);
          break;
        }

      case 1:
        {
          createNewEmployee(employeesArray);
          break;
        }

      case 2:
        {
          searchEmployees(employeesArray);
          break;
        }

      case 3:
        {
          displayEmployees(employeesArray);
          break;
        }

      case 4:
        {
          sortEmployeesArray(employeesArray);
          break;
        }

      case 5:
        {
          modifyEmployeeRecords(employeesArray);
          break;
        }

      case 6:
        {
          fireEmployees(employeesArray);
          break;
        }

      case 7:
        {
          deleteEmployeeRecords(employeesArray);
          break;
        }

      default:
        {
          cout << "\nPlease make a valid choice from the options given." << endl;
          break;
        }
    }
  }

  return 0;
}
