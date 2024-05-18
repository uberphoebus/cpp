#include <iostream>
using namespace std;

template <typename T> class SimpleStaticArray {
private:
  static T mem;

public:
  void AddMem(T num) { mem += num; }
  void ShowMem() { cout << mem << endl; }
};

template <typename T> T SimpleStaticArray<T>::mem = 0;

int main(void) {
  SimpleStaticArray<int> obj1;
  SimpleStaticArray<int> obj2;
  obj1.AddMem(2);
  obj2.AddMem(3);
  obj1.ShowMem();

  SimpleStaticArray<long> obj3;
  SimpleStaticArray<long> obj4;
  obj3.AddMem(100);
  obj4.ShowMem();

  return 0;
}