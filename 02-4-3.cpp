// const : use when function is not changing reference variables

#include <iostream>
using namespace std;

void func(const int &ref) { cout << ref << endl; }

int main(void) {
  int num = 24;
  func(num);

  return 0;
}