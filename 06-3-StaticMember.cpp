#include <iostream>
using namespace std;

class SoSimple {
private:
  static int simObjCnt;

public:
  SoSimple() {
    simObjCnt++;
    cout << simObjCnt << "th SoSimple object" << endl;
  }
};

int SoSimple::simObjCnt = 0;

class SoComplex {
private:
  static int cmxObjCnt;

public:
  SoComplex() {
    cmxObjCnt++;
    cout << cmxObjCnt << "th SoComplex object" << endl;
  }
  SoComplex(SoComplex &copy) {
    cmxObjCnt++;
    cout << cmxObjCnt << "th SoComplex object" << endl;
  }
};

int SoComplex::cmxObjCnt = 0;

int main(void) {
  SoSimple sim1;
  SoSimple sim2;

  SoComplex com1;
  SoComplex com2 = com1;
  SoComplex();

  return 0;
}