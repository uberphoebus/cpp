#include <iostream>
using namespace std;

class First {
public:
  void MyFunc() { cout << "MyFunc" << endl; }
};

class Second : public First {
public:
  void MyFunc() { cout << "SecondFunc" << endl; }
};

class Third : public Second {
public:
  void MyFunc() { cout << "ThirdFunc" << endl; }
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