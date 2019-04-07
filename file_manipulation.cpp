#include "file_manipulation.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool checkFileStream(string filename, bool isFail) {
  if (isFail) {
    cout << "File: " << filename << " cannot be opened. Terminating the program..." << endl;
  } else {
    cout << "File: " << filename << " has been successfully opened, its contents are being loaded..." << endl;
  }

  return !(isFail);
}

ifstream openIfstream(string filename) {
  ifstream fin (filename.c_str());
  return fin;
}
