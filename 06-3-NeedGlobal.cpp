#include <iostream>
#define UNUSED(var) (void)var
using namespace std;

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple {
public:
  SoSimple() {
    simObjCnt++;
    cout << simObjCnt << "th SoSimple object" << endl;
  }
};

class SoComplex {
public:
  SoComplex() {
    cmxObjCnt++;
    cout << cmxObjCnt << "th SoComplex object" << endl;
  }
  SoComplex(SoComplex &copy) {
    UNUSED(copy);
    cmxObjCnt++;
    cout << cmxObjCnt << "th SoComplex object" << endl;
  }
};

int main(void) {
  SoSimple sim1;
  SoSimple sim2;

  SoComplex com1;
  SoComplex com2 = com1;
  UNUSED(com2);
  SoComplex();

  return 0;
}