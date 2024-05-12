#include <iostream>
using namespace std;

class First {
public:
  // virtual
  // If you want to override this function in the derived class
  // Not depending on pointer type, depends on object type
  virtual void MyFunc() { cout << "FirstFunc" << endl; }
};

class Second : public First {
public:
  virtual void MyFunc() { cout << "SecondFunc" << endl; }
};

class Third : public Second {
public:
  virtual void MyFunc() { cout << "ThirdFunc" << endl; }
};

int main(void) {
  Third *tptr = new Third();
  Second *sptr = tptr;
  First *fptr = sptr;

  tptr->MyFunc();
  sptr->MyFunc();
  fptr->MyFunc();

  delete tptr;

  return 0;
}