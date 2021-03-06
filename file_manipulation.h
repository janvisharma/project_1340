#include <string>
#include <fstream>
#include <vector>
#include "employee_class.h"

using namespace std;

bool checkFileStream(string, bool);

bool openIfstream(ifstream &, string);

bool openOfstream(ofstream &, string);

vector <Employee> readEmployeeDataFile(ifstream &);

void writeEmployeeDataFile(ofstream &, vector <Employee>);
