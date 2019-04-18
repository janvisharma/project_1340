#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "employee_class.h"
#include "file_manipulation.h"
#include "navigation.h"
#include "array_manipulation.h"

using namespace std;

int main() {
  Employee janvi; // class constructor

  janvi.setFirstName("Janvi");
  janvi.setLastName("Sharma");
  janvi.setEmployeeId("3035552894");
  janvi.setIsAnEmployee("TRUE");

  // user interface
  // load employee data file
  string employeeDataFilename;

  cout << "Welcome back." << endl;
  cout << "Please input name of employee data file: ";
  cin >> employeeDataFilename;

  ifstream fin;
  bool isOpen = openIfstream(fin, employeeDataFilename);
  while(!isOpen)
  {
    cout << "Please input valid file name: ";
    cin >> employeeDataFilename;
    isOpen = openIfstream(fin, employeeDataFilename);
  }

  vector <Employee> employeesArray = readEmployeeDataFile(fin);
  fin.close();

  // menu-based navigation
  int userChoice = 1;

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

    cout << "-----------------------------------------------------" << endl;

    cout << "Please enter number:\t";
    cin >> userChoice;

    switch (userChoice) {
      // all cases will call a corresponding function from navigation.h
      case 0:
        {
          exitProgram(employeeDataFilename, employeesArray);
          break;
        }

      case 1:
        {
          cout << 1 << endl;
          break;
        }

      case 2:
        {
          searchEmployees(employeesArray);
          break;
        }

      case 4:
        {
          sortEmployeesArray(employeesArray);
          break;
        }

      default:
        {
          cout << "\nPlease enter a valid number from the options given." << endl;
        }
    }
  }

  return 0;
}
