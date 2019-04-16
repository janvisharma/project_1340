#include <iostream>
#include <string>
#include <fstream>
#include "employee_class.h"
#include "file_manipulation.h"
#include "navigation.h"
#include "dynamic_array.h"

using namespace std;

int main() {
  Employee janvi; // class constructor

  janvi.setFirstName("Janvi");
  janvi.setLastName("Sharma");
  janvi.setEmployeeId("3035552894");
  janvi.setIsAnEmployee("TRU");

  cout << "\t\t" << janvi.getIsAnEmployee() << endl;

  // user interface
  // load employee data file
  string employeeDataFilename;

  cout << "Welcome back." << endl;
  cout << "Please input name of employee data file: ";
  cin>>employeeDataFilename;

  ifstream fin;
  bool isOpen = openIfstream(fin, employeeDataFilename);
  while(!isOpen)
  {
    cout << "Please input valid file name: ";
    cin>>employeeDataFilename;
    isOpen = openIfstream(fin, employeeDataFilename);
  }

  Employee * employeesArray = readEmployeeDataFile(fin);
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
    cout << "4: Modify record of an employee." << endl;
    cout << "5: Fire an employee." << endl;

    cout << "-----------------------------------------------------" << endl;

    cout << "Please enter number:\t";
    cin >> userChoice;

    switch (userChoice) {
      // all cases will call a corresponding function from navigation.h
      case 0:
        {
          exitProgram();
        }

      case 1:
        {
          cout << 1 << endl;
        }
    }
  }

  return 0;
}
