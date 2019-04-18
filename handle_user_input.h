#include <string>

using namespace std;

void convertStringToLower(string &);

string handleUserInputLine(string);

// special function for selecting employee attributes for seaching and sorting
bool checkAndConvertToIntegerForEmployeeAttributes(int &, string, int);

string getValueByString(string);

int getValueByInteger(string);

double getValueByDouble(string);

bool getValueByBoolean(string);
