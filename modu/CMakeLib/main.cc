#include "shape.h"
#include <iostream>

int main() {
  Rectangle r(3, 4);
  std::cout << "Area: " << r.getArea() << std::endl;
  return 0;
}