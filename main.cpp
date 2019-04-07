#include <iostream>
#include <string>
#include <fstream>
#include "employee_class.h"
#include "file_manipulation.h"
#include "navigation.h"

using namespace std;

int main() {
  Employee janvi; // class constructor

  janvi.setFirstName("Janvi");
  janvi.setLastName("Sharma");
  janvi.setEmployeeId("3035552894");

  cout << janvi.getFirstName() << " " << janvi.getLastName() << " " << janvi.getEmployeeId() << endl;

  // user interface
  // load employee data file
  const string employee_data_filename = "employee_data.txt";
  ifstream fin = openIfstream(employee_data_filename);
  checkFileStream(employee_data_filename, fin.fail());
  fin.close();

  // menu-based navigation
  int userChoice = 1;

  while (true) {
    cout << "-----------------------------------------------------" << endl;
    cout << "What do you want to do?" << endl;

    // menu
    cout << "0: Exit the program, and record changes to your employee data in the file you loaded." << endl;
    cout << "1: " << endl;

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
