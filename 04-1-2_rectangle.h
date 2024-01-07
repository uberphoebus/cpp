#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "04-1-2_point.h"

class Rectangle {
private:
  Point upLeft;
  Point lowRight;

public:
  bool InitMembers(const Point &ul, const Point &lr);
  void ShowRecInfo() const;
};

#endif