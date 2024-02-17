#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "04-1-2_point.h"

class Rectangle {
private:
  Point upLeft;
  Point lowRight;

public:
  bool InitMembers(const Point &ul, const Point &lr);
  Rectangle(const int &x1, const int &y1, const int &x2,
            const int &y2); // member initializer
  void ShowRecInfo() const;
};

#endif