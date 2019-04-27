#include <string>
#include <vector>
#include "employee_class.h"

using namespace std;

void convertStringToLower(string &);

string handleUserInputLine(string);


bool checkAndConvertToIntegerWithIndexLimit(int &, string, int);

string getValueFromStringStream(string);

string getValueByString(string);

string getValueByLongString(string);

int getValueByInteger(string);

double getValueByDouble(string);

bool getValueByBoolean(string);

vector <int> getIndices(string, string, int);

string getFileName(string);

string setEmployeeBySwitch(Employee &, int);
