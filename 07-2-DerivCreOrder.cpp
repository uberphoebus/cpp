#include <iostream>
using namespace std;

class SoBase {
private:
  int baseNum;

public:
  SoBase() : baseNum(20) { cout << "SoBase() set" << endl; }
  SoBase(int n) : baseNum(n) { cout << "SoBase() default" << endl; }
  void ShowBaseData() { cout << baseNum << endl; }
  ~SoBase() { cout << "~SoBase()" << endl; }
};

class SoDerived : public SoBase {
private:
  int derivNum;

public:
  SoDerived() : derivNum(30) { cout << "SoDerived() set" << endl; }
  SoDerived(int n) : derivNum(n) { cout << "SoDerived() default" << endl; }
  SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2) {
    cout << "SoDerived()" << endl;
  }
  void ShowDerivData() {
    ShowBaseData();
    cout << derivNum << endl;
  }
  ~SoDerived() { cout << "~SoDerived()" << endl; }
};

int main(void) {
  cout << "case 1: " << endl;
  SoDerived dr1;
  dr1.ShowDerivData();
  cout << "----------------------" << endl;
  cout << "case 2: " << endl;
  SoDerived dr2(12);
  dr2.ShowDerivData();
  cout << "----------------------" << endl;
  cout << "case 3: " << endl;
  SoDerived dr3(23, 24);
  dr3.ShowDerivData();

  return 0;
}