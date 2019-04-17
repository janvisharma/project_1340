#include "employee_class.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

Employee::Employee(void) {
  cout << "Creating a new employee..." << endl;
}

// setter functions
void Employee::setFirstName(string input) {
  firstName = input;
}

void Employee::setLastName(string input) {
  lastName = input;
}

void Employee::setEmployeeId(string input) {
  employeeId = input;
}

void Employee::setAge(string input) {
  age = stoi(input);
}

void Employee::setRole(string input) {
  role = input;
}

void Employee::setSalary(string input) {
   salary = stod(input);
}

void Employee::setAddress(string input) {
  address = input;
}

void Employee::setPhoneNumber(string input) {
  phoneNumber = input;
}

void Employee::setDateOfBirth(string input) {
  dateOfBirth = input;
}

void Employee::setIsAnEmployee(string input) {
  transform(input.begin(), input.end(), input.begin(), ::tolower);
  isAnEmployee = input == "true";
}

void Employee::setAllAttributes(string input[]){
  setFirstName(input[0]);
  setLastName(input[1]);
  setEmployeeId(input[2]);
  setAge(input[3]);
  setRole(input[4]);
  setSalary(input[5]);
  setAddress(input[6]);
  setPhoneNumber(input[7]);
  setDateOfBirth(input[8]);
  setIsAnEmployee(input[9]);
}


// getter functions
string Employee::getFirstName() {
  return firstName;
}

string Employee::getLastName() {
  return lastName;
}

string Employee::getEmployeeId() {
  return employeeId;
}

int Employee::getAge() {
  return age;
}

string Employee::getRole() {
  return role;
}

double Employee::getSalary() {
  return salary;
}

string Employee::getAddress() {
  return address;
}

string Employee::getPhoneNumber() {
  return phoneNumber;
}

string Employee::getDateOfBirth() {
  return dateOfBirth;
}

bool Employee::getIsAnEmployee() {
  return isAnEmployee;
}


string * Employee::getAttributesHeader(void) {
  return &attributesHeader[0];
}

int Employee::getNumberOfEmployeeAttributes() {
  return numberOfEmployeeAttributes;
}
