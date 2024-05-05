#include <cstring>
#include <iostream>
using namespace std;

namespace CAR_CONST {
enum {
  ID_LEN = 20,
  MAX_SPD = 200,
  FUEL_STEP = 2,
  ACC_STEP = 10,
  BRK_STEP = 10,
};
}

// class
class Car {
private: // information hiding
  char gamerID[CAR_CONST::ID_LEN];
  int fuelGauge;
  int curSpeed;

public:
  void InitMembers(char *ID, int fuel);
  void ShowCarState();
  void Accel();
  void Break();
};

int main(void) {

  Car run99;
  run99.InitMembers("run99", 100);
  run99.Accel();
  run99.Accel();
  run99.Accel();
  run99.ShowCarState();
  run99.Break();
  run99.ShowCarState();

  return 0;
}

void Car::InitMembers(char *ID, int fuel) {
  strcpy(gamerID, ID);
  fuelGauge = fuel;
  curSpeed = 0;
}
void Car::ShowCarState() {
  cout << "ID    : " << gamerID << endl;
  cout << "fuel  : " << fuelGauge << " %" << endl;
  cout << "speed : " << curSpeed << " km/s" << endl << endl;
}
void Car::Accel() {
  if (fuelGauge <= 0) {
    return;
  } else {
    fuelGauge -= CAR_CONST::FUEL_STEP;
  }

  if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD) {
    curSpeed = CAR_CONST::MAX_SPD;
    return;
  }

  curSpeed += CAR_CONST::ACC_STEP;
}
void Car::Break() {
  if (curSpeed < CAR_CONST::BRK_STEP) {
    curSpeed = 0;
    return;
  }
  curSpeed -= CAR_CONST::BRK_STEP;
}