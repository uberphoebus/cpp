#include "13-2-Point.h"
#include <iostream>
using namespace std;

Point::Point(int x, int y) : xpos(x), ypos(y) {}

ostream &operator<<(ostream &os, const Point &pos) {
  os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
  return os;
}