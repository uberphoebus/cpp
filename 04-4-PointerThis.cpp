#include <cstring>
#include <iostream>
using namespace std;

class SoSimple {
private:
  int num;

public:
  SoSimple(int n) : num(n) {
    cout << "num=" << num << ", ";
    cout << "address=" << this << endl;
  }
  void ShowSimpleData() { cout << num << endl; }
  SoSimple *GetThisPointer() {
    return this;
  } // this는 객체 자신을 가리키는 포인터
};

int main(void) {
  SoSimple sim1(100);
  SoSimple *ptr1 = sim1.GetThisPointer();
  cout << ptr1 << ", ";
  ptr1->ShowSimpleData();

  SoSimple sim2(200);
  SoSimple *ptr2 = sim2.GetThisPointer();
  cout << ptr2 << ", ";
  ptr2->ShowSimpleData();

  cout << &sim1 << endl;
  cout << &sim2 << endl;

  return 0;
}