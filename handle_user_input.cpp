#include "handle_user_input.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>

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

// special function for selecting employee attributes for seaching and sorting
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


// get value by data type functions
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
