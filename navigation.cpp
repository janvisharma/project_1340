#include "navigation.h"
#include "employee_class.h"
#include "array_manipulation.h"
#include "file_manipulation.h"
#include "handle_user_input.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cctype>

using namespace std;


// Additional functions
void centreJustify(string str, int width){
  int strLength = str.length();
  if (strLength > width) {
    strLength = width;
  }
  int pos=(int)((width-strLength)/2);
  for(int i=0;i<pos;i++)
  {
     cout << " ";
  }
  if (strLength == width) {
    str = str.substr(0, width);
  }
  cout << str;
  if (strLength % 2 == 0) {
    pos++;
  }
  for(int i=0;i<pos;i++)
  {
     cout << " ";
  }
  cout << " ";
}

string setPrecision(double s){
  string sal;
  int pos;
  sal = to_string(s);
  pos = sal.find('.')+3;
  if(pos)
  {
    sal.erase(pos);
  }
  return sal;
}

void showEmployeeList(vector <Employee> employeesArray) {
  Employee thisEmployee;
  string header[5]={"First Name","Last Name","Employee ID","Salary","Employee Status"};
  // display index
  cout << "Index ";
  for(int i=0;i<5;i++)
  {
    centreJustify(header[i], 15);
  }
  cout << endl;

  for(int i=0;i<employeesArray.size();i++)
  {
    thisEmployee = employeesArray[i];
    string values[5] = {thisEmployee.getFirstName(),thisEmployee.getLastName(), thisEmployee.getEmployeeId(), setPrecision(thisEmployee.getSalary()) };

    values[4] = thisEmployee.getIsAnEmployee() ? "True" : "False";

    centreJustify(to_string(i + 1), 5);
    for(int j=0;j<5;j++)
    {
      centreJustify(values[j], 15);
    }
    cout<<endl;
  }
}

void showSpecificEmployee(Employee employee) {
  cout << "First Name: " << employee.getFirstName() << endl;
  cout << "Last Name: " << employee.getLastName() << endl;
  cout << "Employee ID: " << employee.getEmployeeId() << endl;
  cout << "Age: " << employee.getAge() << endl;
  cout << "Role: " << employee.getRole() << endl;
  cout << "Salary: " << employee.getSalary() << endl;
  cout << "Address: " << employee.getAddress() << endl;
  cout << "Phone Number: " << employee.getPhoneNumber() << endl;
  cout << "Date of Birth: " << employee.getDateOfBirth() << endl;
  string empStatus = employee.getIsAnEmployee() ? "True" : "False";
  cout << "Employee Status: " << empStatus << endl;
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


// User choice = 1, create new employee record
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
    cout << "\nAny information to be changed before creating employee record? Select between 0 to 9 as previously asked.\nEnter -1 to confirm employee record entered, -2 to cancel creation, and go back to main program.\n" << endl;
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
  while (!checkAndConvertToIntegerWithIndexLimit(attributeInteger, attributeString, numberOfEmployeeAttributes)) {
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
      string searchValue = getValueByLongString("employee id");
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
      string searchValue = getValueByLongString("phone number");
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
  cout << "\n";
  if (filteredEmployeesArray.size() > 0) {
    cout << "Found employee" << (filteredEmployeesArray.size() > 1 ? "s" : "") << ":" << endl;
    // show filtered list of employees
    showEmployeeList(filteredEmployeesArray);
  } else {
    cout << "No employee found..." << endl;
  }
  cout << "\n";

  cout << "*****************************************************" << endl;
}


// User choice = 3, Display all employee records
void displayEmployees(vector <Employee> employeesArray){
  cout << "*****************************************************" << endl;
  showEmployeeList(employeesArray);

  // ask user whether to go back to main menu or look into 1 specific employee
  cout << "Do you wish to display the record of a specific employee?" << endl;
  string userChoice = getValueByString("(y/n)");
  if (userChoice == "y" || userChoice == "Y") {
    int index = getValueByInteger("Index of employee");
    while (index < 1 || index > employeesArray.size()) {
      index = getValueByInteger("Index between 1 and " + to_string(employeesArray.size()));
    }
    showSpecificEmployee(employeesArray[index - 1]);
  }
  cout << endl;

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
  string userPrompt = "Please select attributes to sort accordingly. More than 1 attribute can be selected. Simply order by decreasing importance, separated by a space. Order: ";
  vector <int> order = getIndices(userPrompt, "attributes order", numberOfEmployeeAttributes);

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

  // show list of employees
  showEmployeeList(employeesArray);
  cout << "\n";

  cout << "*****************************************************" << endl;
}

// User choice = 5, Modify employee records
void modifyEmployeeRecords(vector <Employee> & employeesArray){
  cout << "*****************************************************" << endl;

  showEmployeeList(employeesArray);

  string userPrompt = "Enter index of employee record you wish to modify: ";
  string indexString = getValueFromStringStream(userPrompt);
  int index;
  while (!checkAndConvertToIntegerWithIndexLimit(index, indexString, employeesArray.size())) {
    userPrompt = "Invalid index selected. Please input again: ";
    indexString = getValueFromStringStream(userPrompt);
  }

  Employee thisEmployee;
  thisEmployee = employeesArray[index - 1];

  // list all available attributes
  cout << "List of available employee attributes for modifying:" << endl;
  cout << "1: First Name" << endl;
  cout << "2: Last Name" << endl;
  cout << "3: Employee ID" << endl;
  cout << "4: Age" << endl;
  cout << "5: Role" << endl;
  cout << "6: Salary" << endl;
  cout << "7. Address" << endl;
  cout << "8: Phone Number" << endl;
  cout << "9: Date of Birth" << endl;

  int numberOfEmployeeAttributes = 9;

  userPrompt = "Please select 1 attribute as to modify: ";
  string attributeString = getValueFromStringStream(userPrompt);
  int attributeIndex;
  while (!checkAndConvertToIntegerWithIndexLimit(attributeIndex, attributeString, numberOfEmployeeAttributes)) {
    userPrompt = "Invalid attribute selected. Please input again: ";
    attributeString = getValueFromStringStream(userPrompt);
  }

  switch(attributeIndex){
    case 1:
    {
      string firstName = getValueByLongString("first name");
      thisEmployee.setFirstName(firstName);
      break;
    }
    case 2:
    {
      string lastName = getValueByLongString("last name");
      thisEmployee.setLastName(lastName);
      break;
    }
    case 3:
    {
      string employeeId = getValueByLongString("employee id");
      thisEmployee.setEmployeeId(employeeId);
      break;
    }
    case 4:
    {
      int age = getValueByInteger("age");
      thisEmployee.setAge(to_string(age));
      break;
    }
    case 5:
    {
      string role = getValueByLongString("role");
      thisEmployee.setRole(role);
      break;
    }
    case 6:
    {
      double salary = getValueByDouble("salary");
      thisEmployee.setSalary(to_string(salary));
      break;
    }
    case 7:
    {
      string address = getValueByLongString("address");
      thisEmployee.setAddress(address);
      break;
    }
    case 8:
    {
      string phoneNumber = getValueByLongString("phone number");
      thisEmployee.setPhoneNumber(phoneNumber);
      break;
    }
    case 9:
    {
      string dateOfBirth = getValueByLongString("date of birth (Do Month YYYY)");
      thisEmployee.setDateOfBirth(dateOfBirth);
      break;
    }
  }

  // show modified employee (full record)
  cout << "\nModified employee record:" << endl;
  showSpecificEmployee(thisEmployee);
  // prompt user for confirmation
  cout<<"\nAre you sure you wish to continue?" << endl;
  string response = getValueByString("(y/n)");

  if(response == "y" || response == "Y")
  {
    // store thisEmployee into array
    employeesArray[index - 1] = thisEmployee;
  }

  cout << "*****************************************************" << endl;
}
void changeEmployeeStatus(vector <int> indices, vector <Employee> & employeesArray){
  for(int i = 0;i < indices.size(); i++)
  {
    int employeeIndex = indices[i] - 1;
    employeesArray[employeeIndex].setIsAnEmployee("false");
  }
}

// User choice = 6, fire employees
void fireEmployees(vector <Employee> & employeesArray) {
  cout << "*****************************************************" << endl;

  // show employees list
  showEmployeeList(employeesArray);

  bool userConfirmation = true;
  while(userConfirmation){
    // get a vector of employee index
    string userPrompt = "Please select indices to fire accordingly. More than 1 index can be selected, separated by a space. Indices: ";
    vector <int> indices = getIndices(userPrompt, "employee indices", employeesArray.size());

    // prompt for confirmation
    cout << "Are you sure you want to continue? " << endl;
    userConfirmation = getValueByBoolean("(y/n)");

    // if user confirms yes, fire each employee in array by index, by updating isAnEmployee attribute, then return to navigation menu
    if(userConfirmation){
      changeEmployeeStatus(indices, employeesArray);
      break;
    }

    // if user confirms no, prompt if user wants to fire any employees
    cout << "Do you still want to fire an employee? ";
    userConfirmation = getValueByBoolean("(y/n)");

  }
  cout << "\nThe employee list after firing is: " << endl;
  showEmployeeList(employeesArray);

  cout << "*****************************************************" << endl;
}


// User choice = 7, delete employees
void deleteEmployeeRecords(vector <Employee> & employeesArray) {
  cout << "*****************************************************" << endl;

  // show employees list
  showEmployeeList(employeesArray);

  // get a vector of employee index
  bool userConfirmation = false;

  while(!userConfirmation){

    string userPrompt = "Please select indices to delete accordingly. More than 1 index can be selected, separated by a space. Indices: ";
    vector <int> indices = getIndices(userPrompt, "employee indices", employeesArray.size());

    // prompt for confirmation
    cout << "Are you sure you want to continue? " <<  endl;
    userConfirmation = getValueByBoolean("(y/n)");

  }



  cout << "*****************************************************" << endl;
}
