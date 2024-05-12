#include <iostream>
using namespace std;

class SoBase {
private:
  int baseNum;

public:
  SoBase(int n) : baseNum(n) { cout << "SoBase() " << n << endl; }
  ~SoBase() { cout << "~SoBase()" << endl; }
};

class SoDerived : public SoBase {
private:
  int derivNum;

public:
  SoDerived(int n) : SoBase(n), derivNum(n) {
    cout << "SoDerived() " << n << endl;
  }
  ~SoDerived() { cout << "~SoDerived()" << endl; }
};

int main(void) {
  SoDerived dr1(15);
  SoDerived dr2(24);

  return 0;
}