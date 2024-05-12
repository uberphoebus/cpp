#include <cstring>
#include <iostream>
using namespace std;

class Car {
private:
  int gasolineGauge;

public:
  Car(int gas) : gasolineGauge(gas) {}
  int GetGasGauge() { return gasolineGauge; }
  ~Car() { cout << "Car 소멸" << endl; }
};

class HybridCar : public Car {
private:
  int electricGauge;

public:
  HybridCar(int gas, int elec) : Car(gas), electricGauge(elec) {}
  int GetElecGauge() { return electricGauge; }
  ~HybridCar() { cout << "HybridCar 소멸" << endl; }
};

class HybridWaterCar : public HybridCar {
private:
  int waterGauge;

public:
  HybridWaterCar(int gas, int elec, int water)
      : HybridCar(gas, elec), waterGauge(water) {}
  void ShowCurrentGauge() {
    cout << "잔여 가솔린: " << GetGasGauge() << endl;
    cout << "잔여 전기량: " << GetElecGauge() << endl;
    cout << "잔여 워터량: " << waterGauge << endl;
  }
  ~HybridWaterCar() { cout << "HybridWaterCar 소멸" << endl; }
};

int main(void) {
  HybridWaterCar hwc(70, 80, 90);
  hwc.ShowCurrentGauge();

  return 0;
}