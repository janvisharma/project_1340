#include "handle_user_input.h"
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

// special function for selecting employee attributes for seaching and sorting
bool checkAndConvertToIntegerForEmployeeAttributes(int & attributeInteger, string attributeSubstring, int numberOfEmployeeAttributes) {
  bool isInteger = checkAndConvertToInteger(attributeInteger, attributeSubstring);
  return isInteger && 1 <= attributeInteger && attributeInteger <= numberOfEmployeeAttributes;
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
