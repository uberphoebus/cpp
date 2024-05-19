#include <iostream>

#include "foo.h"

int main() {
  int i;
  std::cout << "Hello, Cmake!" << std::endl;
  std::cout << "Foo : " << foo() << std::endl;

  return 0;
}