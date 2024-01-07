#include "04-1-2_rectangle.h"
#include <iostream>
using namespace std;

bool Rectangle::InitMembers(const Point &ul, const Point &lr) {
  if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY()) {
    cout << "value out of range" << endl;
    return false;
  }

  upLeft = ul;
  lowRight = lr;

  return true;
}

void Rectangle::ShowRecInfo() const {
  cout << "upLeft : [" << upLeft.GetX() << ", " << upLeft.GetY() << "]" << endl;
  cout << "lowRight : [" << lowRight.GetX() << ", " << lowRight.GetY() << "]"
       << endl
       << endl;
}
