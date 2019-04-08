#include <iostream>
#include <string>
#include <fstream>
#include "employee_class.h"

using namespace std;

bool checkFileStream(string, bool);

ifstream openIfstream(string);

Employee * readEmployeeDataFile(ifstream&);
