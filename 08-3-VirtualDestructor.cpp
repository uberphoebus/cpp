#include <cstring>
#include <iostream>
using namespace std;

class First {
private:
  char *strOne;

public:
  First(char *str) {
    strOne = new char[strlen(str) + 1];
    strcpy(strOne, str);
  }
  // If the destructor is not virtual, the destructor of the base class is
  // called when the pointer of the base class is deleted, and the destructor
  // of the derived class is not called. This is a problem because the memory
  // allocated in the derived class is not released.
  virtual ~First() {
    delete[] strOne;
    cout << "~First()" << endl;
  }
};

class Second : public First {
private:
  char *strTwo;

public:
  Second(char *str1, char *str2) : First(str1) {
    strTwo = new char[strlen(str2) + 1];
    strcpy(strTwo, str2);
  }
  ~Second() {
    delete[] strTwo;
    cout << "~Second()" << endl;
  }
};

int main() {
  First *ptr = new Second("simple", "complex");
  delete ptr;
  return 0;
}