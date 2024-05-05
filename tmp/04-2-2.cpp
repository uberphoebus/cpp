#include <iostream>
using namespace std;

class SinivelCap {
public:
  void Take() const { cout << "nice sinivel" << endl; }
};

class SneezeCap {
public:
  void Take() const { cout << "nice sneeze" << endl; }
};

class SnuffleCap {
public:
  void Take() const { cout << "nice snuffle" << endl; }
};

// encapsulized
class CONTAC600 {
private:
  SinivelCap sin;
  SneezeCap sne;
  SnuffleCap snu;

public:
  void Take() const {
    sin.Take();
    sne.Take();
    snu.Take();
  }
};

class ColdPatient {
public:
  // encapsulized
  void TakeCONTAC600(const CONTAC600 &cap) const { cap.Take(); }
};

int main(void) {
  // encapsulized
  CONTAC600 cap;
  ColdPatient snufferer;
  snufferer.TakeCONTAC600(cap);

  return 0;
}