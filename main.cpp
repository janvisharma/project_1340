#include <iostream>
#include <string>
#include "employee_class.h"

using namespace std;

int main() {
  Employee janvi;

  janvi.setFirstName("Janvi");
  janvi.setLastName("Sharma");
  janvi.setEmployeeId("3035552894");

  cout << janvi.getFirstName() << " " << janvi.getLastName() << " " << janvi.getEmployeeId() << endl;

  return 0;
}
