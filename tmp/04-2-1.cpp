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

class ColdPatient {
public:
  void TakeSinivelCap(const SinivelCap &cap) const { cap.Take(); }
  void TakeSneezeCap(const SneezeCap &cap) const { cap.Take(); }
  void TakeSnuffleCap(const SnuffleCap &cap) const { cap.Take(); }
};

int main(void) {
  SinivelCap scap;
  SneezeCap zcap;
  SnuffleCap ncap;

  ColdPatient snufferer;
  snufferer.TakeSinivelCap(scap);
  snufferer.TakeSneezeCap(zcap);
  snufferer.TakeSnuffleCap(ncap);

  return 0;
}