#include "handle_user_input.h"
#include "employee_class.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <sstream>

using namespace std;

// convert string to lowercase
void convertStringToLower(string & value) {
  for (int i = 0; i < value.size(); i++) {
    if (isalpha(value[i])) {
      value[i] = tolower(value[i]);
    }
  }
}

// handle generic user input line
string handleUserInputLine(string userPrompt) {
  string inputLine;
  cout << "\n" << userPrompt;
  getline(cin, inputLine);
  while(inputLine.length() == 0) {
    getline(cin, inputLine);
  }
  return inputLine;
}


// check and convert according to data type functions
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

// special function to convert integer, but check if integer is less than index limit
bool checkAndConvertToIntegerWithIndexLimit(int & valueInteger, string substring, int indexLimit) {
  bool isInteger = checkAndConvertToInteger(valueInteger, substring);
  return isInteger && 1 <= valueInteger && valueInteger <= indexLimit;
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


// get value template function
string getValueFromStringStream(string userPrompt) {
  string valueLine = handleUserInputLine(userPrompt);
  istringstream valueStream;
  valueStream.str(valueLine);
  string valueString = "";
  valueStream >> valueString;
  return valueString;
}

// get value by data type functions
string getValueByString(string attribute) {
  string userPrompt = "Please input " + attribute + ": ";
  string valueString = getValueFromStringStream(userPrompt);
  while (valueString.length() == 0) {
    userPrompt = "Please input valid " + attribute + ": ";
    valueString = getValueFromStringStream(userPrompt);
  }
  return valueString;
}

string getValueByLongString(string attribute) {
  string userPrompt = "Please input " + attribute + ": ";
  string valueString = handleUserInputLine(userPrompt);
  while (valueString.length() == 0) {
    userPrompt = "Please input valid " + attribute + ": ";
    valueString = handleUserInputLine(userPrompt);
  }
  return valueString;
}

int getValueByInteger(string attribute) {
  int valueInteger;
  string userPrompt = "Please input " + attribute + ": ";
  string valueString = getValueFromStringStream(userPrompt);
  while (valueString.length() == 0 || !checkAndConvertToInteger(valueInteger, valueString)) {
    userPrompt = "Please input valid " + attribute + ": ";
    valueString = getValueFromStringStream(userPrompt);
  }
  return valueInteger;
}

double getValueByDouble(string attribute) {
  double valueDouble;
  string userPrompt = "Please input " + attribute + ": ";
  string valueString = getValueFromStringStream(userPrompt);
  while (valueString.length() == 0 || !checkAndConvertToDouble(valueDouble, valueString)) {
    userPrompt = "Please input valid " + attribute + ": ";
    valueString = getValueFromStringStream(userPrompt);
  }
  return valueDouble;
}

bool getValueByBoolean(string attribute) {
  bool valueBoolean;
  string userPrompt = "Please input " + attribute + ": ";
  string valueString = getValueFromStringStream(userPrompt);
  while (valueString.length() == 0 || !checkAndConvertToBoolean(valueBoolean, valueString)) {
    userPrompt = "Please input valid " + attribute + ": ";
    valueString = getValueFromStringStream(userPrompt);
  }
  return valueBoolean;
}

vector <int> getIndices(string userPrompt, string purpose, int indexLimit) {
  string inputLine = handleUserInputLine(userPrompt);
  // split inputLine data into vector of integers, also check if all integers are within numberOfEmployeeAttributes boundary
  vector <int> indices;
  bool isValid = false;
  while (!isValid) {
    inputLine += " ";
    while(inputLine.length() != 0) {
      // get substring by removinng spaces
      string subString = "";
      for (int i = 0; i < inputLine.length(); i++) {
        if (!isspace(inputLine[i])) {
          subString += inputLine[i];
        } else {
          break;
        }
      }

      // check if substring is a number that is less than indexLimit
      int valueInteger;
      isValid = checkAndConvertToIntegerWithIndexLimit(valueInteger, subString, indexLimit);

      if (!isValid) {
        vector<int>().swap(indices);
        break;
      }

      // put into indices vector
      indices.push_back(valueInteger);

      // erase substring and subsequent spaces in inputLine
      inputLine.erase(0, subString.length());
      while (inputLine.length() != 0 && isspace(inputLine[0])) {
        inputLine.erase(0, 1);
      }
    }

    // break isValid while loop if inputLine was exhausted properly and indices size is less than numberOfEmployeeAttributes
    if (isValid && indices.size() <= indexLimit) {
      break;
    }
    userPrompt = "Invalid " + purpose + ". Please input again: ";
    inputLine = handleUserInputLine(userPrompt);
  }

  return indices;
}

string getFileName(string prompt) {
  string userPrompt = "Please input " + prompt + ": ";
  string filename = getValueFromStringStream(userPrompt);
  int dotIndex = filename.find('.');
  while (filename.length() - dotIndex - 1 != 3 || filename.substr(dotIndex + 1, 3) != "txt") {
    userPrompt = "Please input valid " + prompt + ": ";
    filename = getValueFromStringStream(userPrompt);
    dotIndex = filename.find('.');
  }
  return filename;
}

string setEmployeeBySwitch(Employee & thisEmployee, int attributeIndex) {
  switch(attributeIndex) {
    case 1:
    {
      string firstName = getValueByLongString("first name");
      thisEmployee.setFirstName(firstName);
      return firstName;
      break;
    }
    case 2:
    {
      string lastName = getValueByLongString("last name");
      thisEmployee.setLastName(lastName);
      return lastName;
      break;
    }
    case 3:
    {
      string employeeId = getValueByLongString("employee id");
      thisEmployee.setEmployeeId(employeeId);
      return employeeId;
      break;
    }
    case 4:
    {
      int age = getValueByInteger("age");
      string ageString = to_string(age);
      thisEmployee.setAge(ageString);
      return ageString;
      break;
    }
    case 5:
    {
      string role = getValueByLongString("role");
      thisEmployee.setRole(role);
      return role;
      break;
    }
    case 6:
    {
      double salary = getValueByDouble("salary");
      string salaryString = to_string(salary);
      thisEmployee.setSalary(salaryString);
      return salaryString;
      break;
    }
    case 7:
    {
      string address = getValueByLongString("address");
      thisEmployee.setAddress(address);
      return address;
      break;
    }
    case 8:
    {
      string phoneNumber = getValueByLongString("phone number");
      thisEmployee.setPhoneNumber(phoneNumber);
      return phoneNumber;
      break;
    }
    case 9:
    {
      string dateOfBirth = getValueByLongString("date of birth (Do Month YYYY)");
      thisEmployee.setDateOfBirth(dateOfBirth);
      return dateOfBirth;
      break;
    }
    case 10:
    {
      double isAnEmployeeDouble = getValueByBoolean("employee status (y/n)");
      string isAnEmployeeString = isAnEmployeeDouble ? "true" : "false";
      thisEmployee.setIsAnEmployee(isAnEmployeeString);
      return isAnEmployeeString;
      break;
    }
    default:
    {
      return "";
      break;
    }
  }
}
