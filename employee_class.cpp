#include "employee_class.h"
#include <iostream>
#include <string>

using namespace std;

void Employee::GetName()
{
  cout<<"Enter name ";
  cin>>name;
  cout<<"NAMEEE "<<name;
}

void Employee::GetId()
{
  cout<<"enter id ";
  cin>>id;
  cout<<"id is "<<id;
}
